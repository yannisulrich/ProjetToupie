#pragma once

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_4_4_Core>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

//size est le nombre de points en 3D. max_size_ est le nombre de floats

class GLTrace {
public:
    GLTrace(QOpenGLFunctions*, const size_t&);
    ~GLTrace();

    void put(float x, float y, float z);
    [[nodiscard]] size_t buffersize() const;

    void draw();
private:
    QOpenGLVertexArrayObject* VAO;
    QOpenGLBuffer* VBO;


    size_t head_ = 0;
    size_t tail_ = 0;
    const size_t maxPointSize;
    const size_t max_size_;
    bool full_ = false;

    float data[3] = {0,0,0};
};


