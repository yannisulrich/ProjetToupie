#include <QKeyEvent>
#include <QTimerEvent>
#include <iostream>
#include <utility>
#include <QCursor>
#include "GLWindow.h"

using namespace std;
GLWindow::GLWindow(Scene* scene_, const int& fps, const int& integSubdiv, std::vector<SupportADessin*>  supports, QWidget* parent):
        QOpenGLWidget(parent), integSubDiv(integSubdiv), fps(fps), supports(std::move(supports))
{
    if (fps == 0) throw std::logic_error("fps cannot be set to 0");


    scene = scene_;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&GLWindow::timerTimeout));
    timer->start(1000.0/fps);
    setMouseTracking(true);
    QCursor c;
    c.setShape(Qt::BlankCursor); //cacher le cursor
    setCursor(c);
    setMinimumSize(1200, 800); //taille minimale de la fenêtre
    chronometre = new QElapsedTimer(); //pour avoir les dt en nanosecondes

}
// ======================================================================
GLWindow::~GLWindow() = default;
// ======================================================================
void GLWindow::initializeGL()
{
    chronometre->start();
    scene->initialize();
    for (auto support : supports) { //pour que dans les supports le premier point soit en t = 0;
        support->dessine(time, scene->system);
    }
}
//les deux méthodes suivantes sont relativement triviales
// ======================================================================
void GLWindow::resizeGL(int width, int height)
{

    scene->resize( width, height );
    glViewport( 0, 0, width, height);
    paintGL();
}


// ======================================================================
void GLWindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    scene->update();

}

// ======================================================================
void GLWindow::timerTimeout()
{

    double dt = chronometre->nsecsElapsed() / 1000000000.0;
    chronometre->start();

    DeltaTs.push_front(dt);
    //On déplace d'abord la caméra
    scene->deplacer(dt,up, down, forw, back, left, right);

    //puis on intègre le système
    if(!paused) {
        time +=  dt;
        scene->integrateSystem(dt, integSubDiv);
        if(TraceWriteCounter == 0) {
            scene->system.addToTraces();
            TraceWriteCounter = 4;
        }
        else --TraceWriteCounter;
    }
    //puis on met à jour le graphisme
    update();

    //puis les autres supports
    for (auto support : supports) {
        support->dessine(time, scene->system);
    }

    everySixtyTimes += 1;
    if(everySixtyTimes == 60) {
        everySixtyTimes = 0;
        measuredFPS = 0;
        for(int i(0); i < 60; ++i) {
            measuredFPS += DeltaTs._points[i];
        }
        measuredFPS /= 60;
        measuredFPS = 1/measuredFPS;
        qDebug() << "fps: " << measuredFPS;
    }
}

// ======================================================================
void GLWindow::pause()
{
    /*
    if (!paused) {
        // dans ce cas le timer ne tourne alors on l'arrête
        timerTimeout(); //on actualise encore une fois la scène pour éviter la perte en précision du au temps restant sur le timer
        timer->stop();
    } else {
        // le timer tourne pas alors on le lance
        timer->start();
        chronometre->restart();
    }
     */
    paused = 1 - paused;

}

void GLWindow::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {

        case Qt::Key_PageUp:
        case Qt::Key_W:
            forw = true;
            break;

        case Qt::Key_PageDown:
        case Qt::Key_S:
            back = true;
            break;

        case Qt::Key_A:
            left = true;
            break;

        case Qt::Key_D:
            right = true;
            break;

        case Qt::Key_Space:
            up = true;
            break;

        case Qt::Key_Shift:
            down = true;
            break;
        case Qt::Key_Escape:
            //pause();
            if(CapturedMouse) {
                CapturedMouse = false;
                QCursor c;
                c.setShape(Qt::ArrowCursor); //rendre le cursor à l'utilisateur
                setCursor(c);
                MouseEntry = true;
            }
            else {
                CapturedMouse = true; //prendre le cursor
                QCursor c;
                c.setShape(Qt::BlankCursor);
                setCursor(c);
            }
            break;
        case Qt::Key_P:
            pause();
            break;

    };

    paintGL(); // redessine
}

void GLWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {

        case Qt::Key_PageUp:
        case Qt::Key_W:
            forw = false;
            break;

        case Qt::Key_PageDown:
        case Qt::Key_S:
            back = false;
            break;

        case Qt::Key_A:
            left = false;
            break;

        case Qt::Key_D:
            right = false;
            break;

        case Qt::Key_Space:
            up = false;
            break;

        case Qt::Key_Shift:
            down = false;
            break;

    }
    paintGL();
}

//La méthode suivante sert à tourner la vue. Pour que la souris ne quitte pas la fenêtre, on la recentre lorsqu'elle quitte
//le rectangle rect()-MouseMargins
// ======================================================================
void GLWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(!CapturedMouse) return;
    if((rect()-MouseMargins).contains(mapFromGlobal(QCursor::pos()))) {
        if(!CursorSet) {

            //cette boucle if évite le saut de la vue lors de l'entrée de la souris
            if(MouseEntry)
            {
                lastMousePosition = event->pos();
                MouseEntry = false;
                CapturedMouse = true;
                return;
            }

            // Récupère le mouvement relatif par rapport à la dernière position de la souris
            QPointF d = event->pos() - lastMousePosition;
            scene->DeltaPitchYaw(- sensitivity*float(d.y()), sensitivity*float(d.x()));

            lastMousePosition = event->pos();
            CursorSet = true;

        }
        if(CursorSet) {
            CursorSet = false;
        }
    }
    else {
        CursorSet = true;
        QCursor::setPos(mapToGlobal(QPoint(width() / 2, height() / 2))); //centrage du cursor

        lastMousePosition = QPoint(width() / 2, height() / 2);
    }
}


