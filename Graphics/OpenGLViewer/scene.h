#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFunctions>
#include "modelloader.h"

#include "model.h"

class Scene : public QOpenGLFunctions_3_3_Core
{
public:
    Scene(Model* model_, Model* model2_): model(model_), model2(model2_) {}
    void initialize();
    void resize(int w, int h);
    void update();
    void cleanup();


private:
    void createShaderProgram( QString vShader, QString fShader);
    void setupLightingAndMatrices();

    void draw();

    QOpenGLShaderProgram m_shaderProgram;

    QMatrix4x4 m_projection, m_view;

    LightInfo m_lightInfo;

    Model* model;
    Model* model2;
};

#endif // SCENE_H
