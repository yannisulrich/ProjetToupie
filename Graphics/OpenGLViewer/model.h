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
    Model() = default;
    Model(const Model&) = delete; //To be sure no very costly copy is accidentally made anywhere

    Model(QString filepath, ModelLoader::PathType pathType, QString texturePath="");

    void loadNew(QString filepath, ModelLoader::PathType pathType, QString texturePath=""); //change loaded model. Only works if model is not initialized.
    void initialize(QOpenGLShaderProgram& m_shaderProgram);
    void cleanup();
    void draw(QOpenGLShaderProgram& m_shaderProgram, QMatrix4x4 objectMatrix, QMatrix4x4 view, QMatrix4x4 projection);

    float bottomPoint() {return _bottomPoint;}
private:
    void createBuffers();
    void createAttributes(QOpenGLShaderProgram & m_shaderProgram);
    void setupMaterials();


    void drawNode(QOpenGLShaderProgram& m_shaderProgram, const Node *node, QMatrix4x4 objectMatrix, const QMatrix4x4& view, const QMatrix4x4& projection);
    void setMaterialUniforms(QOpenGLShaderProgram& m_shaderProgram, MaterialInfo &mater);

    float _bottomPoint;

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
    bool initialized;
};
#endif // MODEL_H
