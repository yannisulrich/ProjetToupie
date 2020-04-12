#include "model.h"
#include <iostream>
Model::Model(QString filepath, ModelLoader::PathType pathType, QString texturePath) :
    m_indexBuffer(QOpenGLBuffer::IndexBuffer)
  , m_filepath(filepath)
  , m_pathType(pathType)
  , m_texturePath(texturePath)
  , m_error(false)
{
}

void Model::initialize(QOpenGLShaderProgram& m_shaderProgram)
{
    this->initializeOpenGLFunctions();

    createBuffers();
    createAttributes(m_shaderProgram);
    setupMaterials();

    glEnable(GL_DEPTH_TEST);
    glClearColor(.9f, .9f, .93f ,1.0f);
}

void Model::createBuffers()
{
    ModelLoader model;

    if(!model.Load(m_filepath, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model.getBuffer(&vertices, &normals, &indices);
    model.getTexture(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.create();
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model.getNodeData();
}

void Model::createAttributes(QOpenGLShaderProgram & m_shaderProgram)
{
    if(m_error)
        return;

    m_vao.bind();
    // Set up the vertex array state
    m_shaderProgram.bind();

    // Map vertex data to the vertex shader's layout location '0'
    m_vertexBuffer.bind();
    m_shaderProgram.enableAttributeArray( 0 );      // layout location
    m_shaderProgram.setAttributeBuffer( 0,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        3);         // number of components (3 for x,y,z)

    // Map normal data to the vertex shader's layout location '1'
    m_normalBuffer.bind();
    m_shaderProgram.enableAttributeArray( 1 );      // layout location
    m_shaderProgram.setAttributeBuffer( 1,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        3);         // number of components (3 for x,y,z)

    if(!m_textureUVBuffer.isCreated())
        return;
    m_textureUVBuffer.bind();
    m_shaderProgram.enableAttributeArray( 2 );      // layout location
    m_shaderProgram.setAttributeBuffer( 2,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        2);         // number of components (2 for u,v)

}

void Model::setupMaterials()
{

    m_materialInfo.Ambient = QVector3D( 0.1f, 0.05f, 0.0f );
    m_materialInfo.Diffuse = QVector3D( .9f, .6f, .2f );
    m_materialInfo.Specular = QVector3D( .2f, .2f, .2f );
    m_materialInfo.Shininess = 50.0f;
}
void Model::draw(QOpenGLShaderProgram& m_shaderProgram, QMatrix4x4 objectMatrix, QMatrix4x4 view, QMatrix4x4 projection) {
    m_vao.bind();
    drawNode(m_shaderProgram, m_rootNode.data(), objectMatrix, view, projection);
    m_vao.release();
}
//TODO: check if things can be passed as reference
void Model::drawNode(QOpenGLShaderProgram& m_shaderProgram, const Node *node, QMatrix4x4 objectMatrix, QMatrix4x4 view, QMatrix4x4 projection)
{
    // Prepare matrices
    objectMatrix *= node->transformation;
    QMatrix4x4 modelMatrix = m_model * objectMatrix;
    QMatrix4x4 modelViewMatrix = view * modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = projection * modelViewMatrix;

    m_shaderProgram.setUniformValue( "MV", modelViewMatrix );// Transforming to eye space
    m_shaderProgram.setUniformValue( "N", normalMatrix );    // Transform normal to Eye space
    m_shaderProgram.setUniformValue( "MVP", mvp );           // Matrix for transforming to Clip space

    // Draw each mesh in this node
    for(int imm = 0; imm<node->meshes.size(); ++imm)
    {

        if(node->meshes[imm]->material->Name == QString("DefaultMaterial"))
            setMaterialUniforms(m_shaderProgram, m_materialInfo);
        else
            setMaterialUniforms(m_shaderProgram, *node->meshes[imm]->material);

        glDrawElements( GL_TRIANGLES, node->meshes[imm]->indexCount, GL_UNSIGNED_INT
                            , (const void*)(node->meshes[imm]->indexOffset * sizeof(unsigned int)) );
    }

    // Recursively draw this nodes children nodes
    for(int inn = 0; inn<node->nodes.size(); ++inn)
        drawNode(m_shaderProgram, &node->nodes[inn], objectMatrix, view, projection);
}

void Model::setMaterialUniforms(QOpenGLShaderProgram& m_shaderProgram, MaterialInfo &mater)
{
    m_shaderProgram.setUniformValue( "Ka", mater.Ambient );
    m_shaderProgram.setUniformValue( "Kd", mater.Diffuse );
    m_shaderProgram.setUniformValue( "Ks", mater.Specular );
    m_shaderProgram.setUniformValue( "shininess", mater.Shininess );
}

void Model::cleanup()
{
}
