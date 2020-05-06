#include "scene.h"
#include "Toupies/Toupie.h"
#include "Integrateur.h"
#include <iostream>
#include <QtCore>
#include <algorithm>
#include <QOpenGLBuffer>
#include <chrono>
#include <memory>
using namespace std;
using namespace std::chrono;
void Scene::initialize()
{

    Q_INIT_RESOURCE(shaders); //comme VueOpenGL est une library cmake, nous choisissons ce moyen de faire en sorte
    // que les shaders soient bien trouvés.
    QResource vertShaderModel("://model_fragment.vert");
    QResource fragShaderModel("://model_fragment.frag");
    createShaderProgram(m_shaderProgram, vertShaderModel.absoluteFilePath(), fragShaderModel.absoluteFilePath());
    QResource fragShaderTrace("://trace_fragment_shader.glsl");
    QResource vertShaderTrace("://trace_vertex_shader.glsl");
    createShaderProgram(t_shaderProgram, vertShaderTrace.absoluteFilePath(), fragShaderTrace.absoluteFilePath());

    setupLightingAndMatrices();

    for(auto i : system.getToupies()) i->model.initialize(m_shaderProgram);

    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glClearColor(.9f, .9f, .93f ,1.0f);

    yaw = pitch = 0;
    r = {-4,2,0};
    v = {0,0,0};
    a = {0,0,0};
    direction = {cos(pitch)*cos(yaw),sin(pitch), cos(pitch)*sin(yaw)};

    float zeros[300] = {};




    GLfloat vertices[] =
            {-0.90f, 0.90f , 0.3f, // Triangle 1
            +0.85f, 0.90f, 0.3,
             +0.85f, 0.90f, 0.3,
             +0.0f, 0.90f, -0.3,
             -0.85f, 0.40f, 0.6,
             +1.85f, 0.90f, 0.3,
                    0.90f, +0.85f,0.3
            };
    /*
    test = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    test.setUsagePattern(QOpenGLBuffer::StaticDraw);
    Q_ASSERT(test.create());
    Q_ASSERT(test.bind());
    test.allocate(sizeof(vertices));
    test.write(0, vertices, sizeof(vertices));

    const int vPosition = 0;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glEnableVertexAttribArray(vPosition);
    */
    /*
    m_vao.create();
    m_vao.bind();
    QOpenGLBuffer m_vvbo(QOpenGLBuffer::VertexBuffer);
    m_vvbo.create();
    m_vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vvbo.bind();
    m_vvbo.allocate(vertices, 21 * sizeof(float));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    */
    for(size_t i(0); i < system.getToupies().size(); ++i) {
        QtVAOs.push_back(make_unique<QOpenGLVertexArrayObject>());
        QtVAOs[i]->create();
        QtVAOs[i]->bind();
        QtVBOs.push_back(make_unique<QOpenGLBuffer>());
        QtVBOs[i]->create();
        QtVBOs[i]->setUsagePattern(QOpenGLBuffer::DynamicDraw);
        QtVBOs[i]->bind();
        QtVBOs[i]->allocate(zeros, 1200);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    /*
    for(size_t i(0); i < system.getToupies().size(); ++i) {
        TraceGVAOs.push_back(0);
        TraceGVBOs.push_back(0);
        glGenVertexArrays(1, &TraceGVAOs[i]);
        glGenBuffers(1, &TraceGVBOs[i]);


        glBindVertexArray(TraceGVAOs[i]);
        glBindBuffer(GL_ARRAY_BUFFER, TraceGVBOs[i]);
        glBufferData(GL_ARRAY_BUFFER, 1200, zeros, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    */
    /*
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's
     //bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
     */

    table.initialize(m_shaderProgram);
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
    auto start = high_resolution_clock::now();

    // Clear buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    m_shaderProgram.bind();
    m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );
    QMatrix4x4 tableMat;
    tableMat.scale(0.1);
    //table.draw(m_shaderProgram, tableMat, m_view, m_projection);
    dessine(system);

    m_shaderProgram.release();
    /*
    if(TraceWriteCounter == 0) {
        system.addToTraces();
        TraceWriteCounter = 4;

        cout << "1: " << system.getToupies()[0]->TraceG._points.size() << endl;
        for(size_t i(0); i < system.getToupies()[0]->TraceG.size()-2; i += 3) {
            cout << "{" << system.getToupies()[0]->TraceG._points[i] << ", " << system.getToupies()[0]->TraceG._points[i+1]
                 << ", " << system.getToupies()[0]->TraceG._points[i+2] << "},";
        }


    }
    else --TraceWriteCounter;
    */
    t_shaderProgram.bind();

    t_shaderProgram.setUniformValue("projection", m_projection);
    t_shaderProgram.setUniformValue("vue_modele", m_view);

    /*
    float vertices[] = { // top right
            0.0f, 1.0f, 0.0f,  // bottom right
            0.0f, 1.0f, 1.0f,  // bottom left
            1.0f,  1.0f, 1.0f,   // top left
            1.0f,  1.0f, 0.0f,
            1.0f,  2.0f, 0.0f,
            1.0f,  2.0f, 1.0f
    };
    float bufferCopy[300] {};
    */
    start = high_resolution_clock::now();
    for(size_t i(0); i < system.getToupies().size(); ++i) {
        float trace[300] = {};
        for (int j(0); j < system.getToupies()[i]->TraceG._points.size(); ++j)
            trace[j] = system.getToupies()[i]->TraceG._points[j];
        QtVAOs[i]->bind();
        QtVBOs[i]->bind();
        //QtVBOs[i]->allocate(1200);
        void *ptr = QtVBOs[i]->map(QOpenGLBuffer::WriteOnly);
        memcpy(ptr, trace,
                4*system.getToupies()[i]->TraceG._points.size());
        QtVBOs[i]->unmap();
        glDrawArrays(GL_LINE_STRIP, 0, system.getToupies()[i]->TraceG._points.size()/3);
    }
        /*
         *
        for(size_t i(0); i < system.getToupies().size(); ++i) {
            float trace[300] = {};
            for (int j(0); j < system.getToupies()[i]->TraceG._points.size(); ++j) trace[j] = system.getToupies()[i]->TraceG._points[j];

            glBindVertexArray(TraceGVAOs[i]);
            glBindBuffer(GL_ARRAY_BUFFER, TraceGVBOs[i]);
            //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBufferSubData(GL_ARRAY_BUFFER, 0, 4*system.getToupies()[i]->TraceG._points.size(), trace);

            //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*system.getToupies()[i]->TraceG._points.size(), &system.getToupies()[i]->TraceG._points.front());
            //void *ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
            //memcpy(ptr, vertices, sizeof(vertices));
            //memcpy(ptr, &system.getToupies()[i]->TraceG._points.front(), sizeof(float)*system.getToupies()[i]->TraceG._points.size());
            //glUnmapBuffer(GL_ARRAY_BUFFER);
            //glGetBufferSubData(GL_ARRAY_BUFFER, 0,1200, bufferCopy);
            //glDrawArrays(GL_LINE_STRIP, 0, 6);

            glDrawArrays(GL_LINE_STRIP, 0, system.getToupies()[i]->TraceG._points.size()/3);
            glBindVertexArray(0);

        }
        */
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function on average: " << duration.count() << " nanoseconds" << endl;
    /*
    if(TraceWriteCounter == 0) {
        cout << endl << "bufferCopy";
        for (auto i : bufferCopy)
            cout << i << " ";
        cout << endl;
    }
    */
    /*
    m_vao.bind(); //sets
    glDrawArrays(GL_TRIANGLES, 0, 6);
    m_vao.release();
    */
    t_shaderProgram.release();
}
void Scene::cleanup()
{
}
//Angles d'euler. 28.647889... est le facteur de conversion entre radians et degrés.
void Scene::dessine(const Toupie & toupie) const {
    //transformation nécessaires pour les angles d'euler.
    QMatrix4x4 modelMatrix;
    modelMatrix.translate(toupie.translationModel());
    modelMatrix.rotate(fmod(toupie.P.getCoord(1)*57.2958, 360.0), 0.0, 1.0, 0.0f);
    modelMatrix.rotate(toupie.P.getCoord(0)*57.2958, 1.0f, 0.0, 0.0);
    modelMatrix.rotate(fmod(toupie.P.getCoord(2)*57.2958, 360.0), 0.0, 1.0, 0.0f);
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
    r[1] = std::max(0.25f, r[1]);
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

