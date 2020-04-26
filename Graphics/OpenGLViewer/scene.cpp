#include "scene.h"
#include "Toupies/Toupie.h"
#include "Integrateur.h"
#include <iostream>
#include <QtCore>
using namespace std;
void Scene::initialize()
{

    Q_INIT_RESOURCE(shaders); //comme VueOpenGL est une library cmake, nous choisissons ce moyen de faire en sorte que les shaders soient bien trouvés.
    QResource vertShader("://ads_fragment.vert");
    QResource fragShader("://ads_fragment.frag");
    createShaderProgram(vertShader.absoluteFilePath(), fragShader.absoluteFilePath());
    m_shaderProgram.bind();

    setupLightingAndMatrices();

    for(auto i : system.getToupies()) i->model.initialize(m_shaderProgram);

    glEnable(GL_DEPTH_TEST);
    glClearColor(.9f, .9f, .93f ,1.0f);

    yaw = pitch = 0;
    r = {-4,0,0};
    v = {0,0,0};
    a = {0,0,0};
    direction = {cos(pitch)*cos(yaw),sin(pitch), cos(pitch)*sin(yaw)};

}

void Scene::createShaderProgram(QString vShader, QString fShader)
{
    // Compile vertex shader
    if ( !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, vShader.toUtf8() ) )
        qCritical() << "Unable to compile vertex shader. Log:" << m_shaderProgram.log();

    // Compile fragment shader
    if ( !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, fShader.toUtf8() ) )
        qCritical() << "Unable to compile fragment shader. Log:" << m_shaderProgram.log();

    // Link the shaders together into a program
    if ( !m_shaderProgram.link() )
        qCritical() << "Unable to link shader program. Log:" << m_shaderProgram.log();
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
                0.3f,           // near clipping plane
                1000.0f);       // far clipping plane

    m_lightInfo.Position = QVector4D( -1.0f, 1.0f, 3.0f, 1.0f );
    //m_lightInfo.Intensity = QVector3D( .5f, .5f, .f5);
    m_lightInfo.Intensity = QVector3D( 1.0f, 1.0f, 1.0f);
}

void Scene::resize(int w, int h)
{
    glViewport( 0, 0, w, h );

    m_projection.setToIdentity();
    m_projection.perspective(60.0f, (float)w/h, .3f, 1000);
}

void Scene::update()
{

    // Clear buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




    m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );

    dessine(system);

    m_shaderProgram.setUniformValue( "MV", m_view );
    QMatrix3x3 normalMatrix = m_view.normalMatrix();
    QMatrix4x4 mvp = m_projection * m_view;

    m_shaderProgram.setUniformValue( "MV", m_view );// Transforming to eye space
    m_shaderProgram.setUniformValue( "N", normalMatrix );    // Transform normal to Eye space
    m_shaderProgram.setUniformValue( "MVP", mvp );
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };
    // This will identify our vertex buffer
    GLuint vertexbuffer;
// Generate 1 buffer, put the resulting identifier in vertexbuffer

    glGenBuffers(1, &vertexbuffer);
// The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );
// Draw the triangle !
    glDrawArrays(GL_LINES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}
void Scene::cleanup()
{
}
//Angles d'euler. 28.647889... est le facteur de conversion entre radians et degrés.
void Scene::dessine(const Toupie & toupie) const {
    //transformation nécessaires pour les angles d'euler.
    QMatrix4x4 modelMatrix;
    modelMatrix.translate(toupie.translationModel());
    modelMatrix.rotate(toupie.P.getCoord(1)*28.6478897565, 0.0, 1.0, 0.0f);
    modelMatrix.rotate(toupie.P.getCoord(0)*28.6478897565, 1.0f, 0.0, 0.0);
    modelMatrix.rotate(toupie.P.getCoord(2)*28.6478897565, 0.0, 1.0, 0.0f);
    modelMatrix.scale(toupie.modelScale());
    if (toupie.type() == "Conique Simple") modelMatrix.translate(0,- toupie.model.bottomPoint(),0);

    toupie.model.draw(m_shaderProgram, modelMatrix, m_view, m_projection);
}

void Scene::dessine(const Systeme & sys) const {
    for(auto i: sys.getToupies()) {
        if(i->hasModel()) dessine(*i);
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

