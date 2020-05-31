#include "scene.h"
#include "Toupies/Toupie.h"
#include <iostream>
#include <QtCore>
#include <algorithm>
#include <QOpenGLBuffer>
#include <chrono>
#include <memory>
using namespace std;
using namespace std::chrono;


Scene::Scene(Integrateur *integrateur, const int& screenw, const int& screenh, const int& traceLength, const QString &tableModelpath):
        system(this, integrateur), SCR_WIDTH(screenw), SCR_HEIGHT(screenh), traceLength(traceLength) {

    if(tableModelpath.isEmpty()) table = new Model(QString("Graphics/OpenGLViewer/Models/tabledefault.DAE"),ModelLoader::RelativePath);
    else table = new Model(tableModelpath,ModelLoader::RelativePath);


}

void Scene::initialize()
{

    toupies = system.getToupies();

    Q_INIT_RESOURCE(shaders); //comme VueOpenGL est une library cmake, nous choisissons ce moyen de faire en sorte
    // que les shaders soient bien trouvés.
    QResource vertShaderModel("://model_fragment.vert");
    QResource fragShaderModel("://model_fragment.frag");
    createShaderProgram(m_shaderProgram, vertShaderModel.absoluteFilePath(), fragShaderModel.absoluteFilePath());
    QResource fragShaderTrace("://trace_fragment_shader.glsl");
    QResource vertShaderTrace("://trace_vertex_shader.glsl");
    createShaderProgram(t_shaderProgram, vertShaderTrace.absoluteFilePath(), fragShaderTrace.absoluteFilePath());

    setupLightingAndMatrices();

    for(auto i : toupies) i->model.initialize(m_shaderProgram);

    initializeOpenGLFunctions();


    glEnable(GL_DEPTH_TEST);

    glClearColor(.9f, .9f, .93f ,1.0f);

    yaw = pitch = 0;
    r = {-4,2,0};
    v = {0,0,0};
    a = {0,0,0};
    direction = {cos(pitch)*cos(yaw),sin(pitch), cos(pitch)*sin(yaw)};

    //initialisation des traces
    for(size_t i(0); i < toupies.size(); ++i) {
        GTraces.push_back(make_unique<GLTrace>(this, traceLength));
        ATraces.push_back(make_unique<GLTrace>(this, traceLength));
    }
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    table->initialize(m_shaderProgram);

    //Shadow init
    QResource fragShaderShadow("://shadow.frag");
    QResource vertShaderShadow("://shadow.vert");
    createShaderProgram(shadow_shaderProgram, vertShaderShadow.absoluteFilePath(), fragShaderShadow.absoluteFilePath());
    shadow_shaderProgram.setUniformValue("diffuseTexture", 0);
    shadow_shaderProgram.setUniformValue("shadowMap", 1);

    glGenFramebuffers(1, &depthMapFBO);
    // create depth texture
    glGenTextures(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    // attach depth texture as FBO's depth buffer
    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    lightPos = {-2.0f, 4.0f, -1.0f};
    lightProjection.ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView.lookAt(lightPos, QVector3D(0.0f,0.0f,0.0f), QVector3D(0.0, 1.0, 0.0));
    lightSpaceMatrix = lightProjection * lightView;


}

void Scene::createShaderProgram(QOpenGLShaderProgram& shaderProgram, const QString& vShader, const QString& fShader)
{
    // Compile vertex shader
    if ( !shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, vShader.toUtf8() ) )
        qCritical() << "Unable to compile vertex shader. Log:" << shaderProgram.log();

    // Compile fragment shader
    if ( !shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, fShader.toUtf8() ) )
        qCritical() << "Unable to compile fragment shader. Log:" << shaderProgram.log();

    // Link the shaders together into a program
    if ( !shaderProgram.link() )
        qCritical() << "Unable to link shader program. Log:" << shaderProgram.log();
}

void Scene::setupLightingAndMatrices()
{
    m_view.setToIdentity();
    m_view.lookAt(
                QVector3D(3.0f, 1.5f, 0.0f),    // Camera Position
                QVector3D(0.0f, 0.0f, 0.0f),    // Point camera looks towards
                QVector3D(0.0f, 1.0f, 0.0f));   // Up vector

    float aspect = 4.0f/3.0f;
    m_projection.setToIdentity();
    m_projection.perspective(
                60.0f,          // field of vision
                aspect,         // aspect ratio
                0.1f,           // near clipping plane
                1000.0f);       // far clipping plane

    m_lightInfo.Position = QVector4D( -1.0f, 1.0f, 3.0f, 1.0f );
    m_lightInfo.Intensity = QVector3D( 1.0f, 1.0f, 1.0f);
}

void Scene::resize(int w, int h)
{
    glViewport( 0, 0,devicePixelRatio*w, devicePixelRatio*h );
    SCR_WIDTH = w;
    SCR_HEIGHT = h;

    m_projection.setToIdentity();
    m_projection.perspective(atan(tan(50.0 * 3.14159 / 360.0) / zoomFactor) * 360.0 / 3.14159, (float)w/h, .1f, 1000);
}

void Scene::update()
{
    ++runCount;
    // Clear buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Shadows
    shadow_shaderProgram.bind();

    shadow_shaderProgram.setUniformValue("lightSpaceMatrix", lightSpaceMatrix);
    shadow_shaderProgram.setUniformValue("shadowMap", 1);

    glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);

    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glClear(GL_DEPTH_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE0);
    QMatrix4x4 tableMat;
    tableMat.scale(100);


    dessineSystem(shadow_shaderProgram);


    glBindFramebuffer(GL_FRAMEBUFFER, 0);


    glViewport(0, 0, devicePixelRatio*SCR_WIDTH, devicePixelRatio*SCR_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shadow_shaderProgram.release();

    //Real drawing
    m_shaderProgram.bind();
    m_shaderProgram.setUniformValue("lightPos", lightPos);
    //m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );
    m_shaderProgram.setUniformValue("lightSpaceMatrix", lightSpaceMatrix);


    m_shaderProgram.setUniformValue("drawShadows", false);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, depthMap);

    dessineSystem(m_shaderProgram);

    m_shaderProgram.setUniformValue("drawShadows", true);
    table->draw(m_shaderProgram, tableMat, m_view, m_projection);

    m_shaderProgram.release();

    //Traces des toupies
    t_shaderProgram.bind();

    t_shaderProgram.setUniformValue("projection", m_projection);
    t_shaderProgram.setUniformValue("vue_modele", m_view);

    t_shaderProgram.setUniformValue("traceColor", 1.0f, 0.5f, 0.2f, 1.0f);

    for(unique_ptr<GLTrace>& trace : GTraces) {
        trace->draw();
    }

    t_shaderProgram.setUniformValue("traceColor", 0.0f, 1.0f, 0.6f, 1.0f);
    for(unique_ptr<GLTrace>& trace : ATraces) {
        trace->draw();
    }

    t_shaderProgram.release();

}
//Angles d'euler. 28.647889... est le facteur de conversion entre radians et degrés.
void Scene::dessine(const Toupie & toupie) const {
    //transformation nécessaires pour les angles d'euler.
    QMatrix4x4 modelMatrix;
    modelMatrix.translate(scaleFactor*toupie.translationModel());
    //Euler
    modelMatrix.rotate(fmod(toupie.P.getCoord(1)*57.2958, 360.0), 0.0, 1.0, 0.0f);
    modelMatrix.rotate(toupie.P.getCoord(0)*57.2958, 1.0f, 0.0, 0.0);
    modelMatrix.rotate(fmod(toupie.P.getCoord(2)*57.2958, 360.0), 0.0, 1.0, 0.0f);
    //Scaling suivant les dimensions, pour que la toupie ai l'air d'avoir les bonnes dimensions
    modelMatrix.scale(scaleFactor*toupie.modelScale());
    //translation verticale. Ceci est fait ici et pas dans les classes pour permettre à l'utilisateur de ne pas devoir centrer son modèle 3D en un point en particulier.
    if (toupie.type() == "Conique Simple" || toupie.type() == "Cone Glissant") modelMatrix.translate(0,- toupie.model.bottomPoint(),0);

    toupie.model.draw(m_shaderProgram, modelMatrix, m_view, m_projection);
}
void Scene::dessine(const Toupie & toupie, QOpenGLShaderProgram& shader) const {
    //transformation nécessaires pour les angles d'euler.
    QMatrix4x4 modelMatrix;
    modelMatrix.translate(scaleFactor*toupie.translationModel());
    //Euler
    modelMatrix.rotate(fmod(toupie.P.getCoord(1)*57.2958, 360.0), 0.0, 1.0, 0.0f);
    modelMatrix.rotate(toupie.P.getCoord(0)*57.2958, 1.0f, 0.0, 0.0);
    modelMatrix.rotate(fmod(toupie.P.getCoord(2)*57.2958, 360.0), 0.0, 1.0, 0.0f);
    //Scaling suivant les dimensions, pour que la toupie ai l'air d'avoir les bonnes dimensions
    modelMatrix.scale(scaleFactor*toupie.modelScale());
    //translation verticale. Ceci est fait ici et pas dans les classes pour permettre à l'utilisateur de ne pas devoir centrer son modèle 3D en un point en particulier.
    if (toupie.type() == "Conique Simple" || toupie.type() == "Cone Glissant") modelMatrix.translate(0,- toupie.model.bottomPoint(),0);

    toupie.model.draw(shader, modelMatrix, m_view, m_projection);
}
void Scene::dessine(const Systeme & sys) const {
    for(auto i: sys.getToupies()) {
        if(i->hasModel()) dessine(*i);
    }
}
void Scene::dessineSystem(QOpenGLShaderProgram & shaderProgram) const {
    for(auto i: toupies) {
        if(i->hasModel()) dessine(*i, shaderProgram);
    }
}
void Scene::integrateSystem(const double &dt, const int& integSubDiv) {
    system.integrateMultiple(integSubDiv, dt/double(integSubDiv));
}

void Scene::deplacer(const double &dt, bool up, bool down, bool forw, bool back, bool left, bool right) {
    //intégration Euler-Cromer avec vitesse bornée
    directionXZPlane = direction;
    directionXZPlane[1] = 0;
    if(up) a += 10*QVector3D({0,1,0});
    if(down) a -= 10*QVector3D({0,1,0});
    if(forw) a += 10 * directionXZPlane;
    if(back) a -= 10 * directionXZPlane;
    if(left) a += 50* QVector3D::normal({0,1,0}, directionXZPlane);
    if(right) a -= 50 *QVector3D::normal({0,1,0}, directionXZPlane);

    a = a.normalized() * std::min(10.0f, a.length());


    v += dt*(a - 2*v);
    v = v.normalized() * std::min(10.0f, v.length());

    r += dt * v;
    r[1] = std::max(0.4f, r[1]);
    m_view.setToIdentity();
    m_view.lookAt(r, r + direction, {0,1,0});

    a *= 0.5;
}
void Scene::DeltaPitchYaw(const float &p, const float &y)
{
    pitch += p;
    yaw += y;
    if(pitch > 1.50f) //Borner le pitch à une valeur absolue  < 90° permet d'éviter les problèmes quand pitch = 90°.
        pitch = 1.50f;
    if(pitch < -1.50f)
        pitch = -1.50f;
    direction = {cos(pitch)*cos(yaw),sin(pitch), cos(pitch)*sin(yaw)};
    m_view.setToIdentity();
    m_view.lookAt(r, r + direction, {0,1,0});

}

void Scene::setZoomPerspectiveMatrix(const int& width, const int& height) {
    m_projection.setToIdentity();
    m_projection.perspective(atan(tan(50.0 * 3.14159 / 360.0) / zoomFactor) * 360.0 / 3.14159, (float)width/height, .1f, 1000);
}

void Scene::addToTraces() {

    for(size_t i(0); i < toupies.size(); ++i) {
        Vecteur3 G = toupies[i]->getGTrace();
        GTraces[i]->put(scaleFactor*G[0], scaleFactor*G[1], scaleFactor*G[2]);
        Vecteur3 A = toupies[i]->getATrace();
        ATraces[i]->put(scaleFactor*A[0], scaleFactor*A[1], scaleFactor*A[2]);
    }
}

