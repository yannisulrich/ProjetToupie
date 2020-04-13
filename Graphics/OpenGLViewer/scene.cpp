#include "scene.h"


void Scene::initialize()
{
    this->initializeOpenGLFunctions();
    //QFileInfo info("ads_fragment.vert");
    //qDebug() << info.absoluteFilePath();
    createShaderProgram("ads_fragment.vert", "ads_fragment.frag");

    setupLightingAndMatrices();

    model->initialize(m_shaderProgram);
    model2->initialize(m_shaderProgram);
    glEnable(GL_DEPTH_TEST);
    glClearColor(.9f, .9f, .93f ,1.0f);
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
                QVector3D(0.0f, 0.0f, 1.2f),    // Camera Position
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

    // Clear color and depth buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind shader program
    m_shaderProgram.bind();

    // Set the model matrix
    // Translate and rotate it a bit to get a better view of the model
    QMatrix4x4 m_model;
    m_model.setToIdentity();
    m_model.translate(-0.2f, 0.0f, .5f);
    m_model.rotate(55.0f, 0.0f, 1.0f, 0.0f);
    // Set shader uniforms for light information
    m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );

    // Bind VAO and draw everything
    model->draw(m_shaderProgram, m_model, m_view, m_projection);
    m_model.setToIdentity();
    m_model.translate(-0.2f, 0.0f, .5f);
    model2->draw(m_shaderProgram, m_model, m_view, m_projection);
}
void Scene::cleanup()
{
}
