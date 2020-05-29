#pragma once

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_4_4_Core>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

//size est le nombre de points en 3D. max_size_ est le nombre de floats
template <size_t maxPointSize>
class GLTrace {
public:
    GLTrace(QOpenGLFunctions*);
    ~GLTrace();

    void put(float x, float y, float z);
    size_t buffersize() const;

    void draw();
private:
    QOpenGLVertexArrayObject* VAO;
    QOpenGLBuffer* VBO;


    size_t head_ = 0;
    size_t tail_ = 0;
    const size_t max_size_;
    bool full_ = false;

    float data[3] = {0,0,0};
};
template <size_t maxPointSize>
GLTrace<maxPointSize>::GLTrace(QOpenGLFunctions* scene): max_size_(3*maxPointSize)  {
    float zeros[3 * maxPointSize] = {};

    VAO = new QOpenGLVertexArrayObject();
    VAO->create();
    VAO->bind();
    VBO = new QOpenGLBuffer();

    VBO->create();
    VBO->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    VBO->bind();
    VBO->allocate(zeros, sizeof(zeros));

    scene->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    scene->glEnableVertexAttribArray(0);


}
template <size_t maxPointSize>
void GLTrace<maxPointSize>::put(float x, float y, float z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;

    VAO->bind();
    VBO->bind();

    void *ptr = VBO->mapRange(4 * head_, 12, QOpenGLBuffer::RangeWrite | QOpenGLBuffer::RangeUnsynchronized);
    memcpy(ptr, data, sizeof(data));
    VBO->unmap();

    if(head_ == max_size_ - 3) {
        void *ptr2 = VBO->mapRange(0, 12, QOpenGLBuffer::RangeWrite | QOpenGLBuffer::RangeUnsynchronized);
        memcpy(ptr2, data, sizeof(data));
        VBO->unmap();
        head_ = 3;
        tail_ = 3;
        full_ = true;
        return;
    }

    if(full_)
    {
        tail_ = (tail_ + 3) % max_size_;
    }
    head_ = (head_ + 3) % max_size_;
    full_ = head_ == tail_;
}
template <size_t maxPointSize>
size_t GLTrace<maxPointSize>::buffersize() const
{
    size_t length = max_size_;

    if(!full_)
    {
        if(head_ >= tail_)
        {
            length = head_ - tail_;
        }
        else
        {
            length = max_size_ + head_ - tail_;
        }
    }

    return length;
}
template <size_t maxPointSize>
GLTrace<maxPointSize>::~GLTrace() {
    delete VAO;
    delete VBO;
}

template<size_t maxPointSize>
void GLTrace<maxPointSize>::draw() {
    VAO->bind();
    VBO->bind();

    if(head_ == tail_ && !full_) return; //empty buffer

    if(!full_) {
        glDrawArrays(GL_LINE_STRIP, 0, (head_ - tail_)/3);
    }
    else {
        glDrawArrays(GL_LINE_STRIP, 0, tail_/3);
        glDrawArrays(GL_LINE_STRIP, tail_/3, (max_size_ - tail_)/3);
    }
}
