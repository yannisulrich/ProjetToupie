#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QWindow>
#include <QOpenGLContext>
#include <QElapsedTimer>
#include "scene.h"

class OpenGLWindow : public QWindow
{
    Q_OBJECT

public:
    OpenGLWindow(Scene*, int refreshRate, int major=3, int minor=3, QScreen* screen = 0 );
    ~OpenGLWindow();

protected:
    void initializeGL();

private:
    QTimer *m_timer;
    Scene *m_scene;
    QOpenGLContext* m_context;
protected slots:
    void updateGL();
    void resizeGL();
    void cleanup();
};

#endif // OPENGLWINDOW_H
