#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFunctions>
#include "modelloader.h"

class Model: public QOpenGLFunctions_3_3_Core
{
public:
    Model(QString filepath, ModelLoader::PathType pathType, QString texturePath="");
    void initialize(QOpenGLShaderProgram& m_shaderProgram);
    void resize(int w, int h);
    void update();
    void cleanup();
    void draw(QOpenGLShaderProgram& m_shaderProgram, QMatrix4x4 objectMatrix, QMatrix4x4 view, QMatrix4x4 projection);

private:
    void createBuffers();
    void createAttributes(QOpenGLShaderProgram & m_shaderProgram);
    void setupMaterials();


    void drawNode(QOpenGLShaderProgram& m_shaderProgram, const Node *node, QMatrix4x4 objectMatrix, QMatrix4x4 view, QMatrix4x4 projection);
    void setMaterialUniforms(QOpenGLShaderProgram& m_shaderProgram, MaterialInfo &mater);

    QOpenGLVertexArrayObject m_vao;

    QOpenGLBuffer m_vertexBuffer;
    QOpenGLBuffer m_normalBuffer;
    QOpenGLBuffer m_textureUVBuffer;
    QOpenGLBuffer m_indexBuffer;

    QSharedPointer<Node> m_rootNode;

    QMatrix4x4 m_model;

    QString m_filepath;
    ModelLoader::PathType m_pathType;
    QString m_texturePath;

    MaterialInfo m_materialInfo;

    bool m_error;
};
#endif // MODEL_H
