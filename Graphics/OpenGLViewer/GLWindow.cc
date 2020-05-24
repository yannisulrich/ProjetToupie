#include <QKeyEvent>
#include <QTimerEvent>
#include <iostream>
#include <utility>
#include <QCursor>
#include <algorithm>
#include <QCloseEvent>
#include "GLWindow.h"
#include <QPaintDevice>


using namespace std;
GLWindow::GLWindow(Scene* scene_, const int& fps, const int& integSubdiv, std::vector<SupportADessin*>  supports, const float& scaleFactor, const int& dpr, QWidget* parent):
        QOpenGLWidget(parent), integSubDiv(integSubdiv), fps(fps), supports(std::move(supports)), measuredFPS(60)
{
    if (fps == 0) throw std::logic_error("fps cannot be set to 0");

    scene = scene_;

    scene->setDevicePixelRatio(dpr);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&GLWindow::timerTimeout));
    timer->start(int(1000.0/fps));
    setMouseTracking(true);
    /*
    QCursor c;
    c.setShape(Qt::BlankCursor); //cacher le cursor
    setCursor(c);
     */
    setMinimumSize(1200, 800); //min. size
    chronometre = new QElapsedTimer(); //For precise delta t measurements

    scene->setScaleFactor(scaleFactor);

    setAttribute( Qt::WA_DeleteOnClose );

    for(int i(0); i < scene->system.getToupies().size(); ++i) {
        const Toupie* toupie = scene->system.getToupies()[i];
        for(int j(0); j< 4; ++j) {
            if (toupie->getPlots()[j]) {
                plots.push_back(make_unique<PlotWindow>(this));
                plotIndexes.emplace_back(i,j);
                switch (j) {
                    case 0: {
                        plots.back()->setWindowTitle(QString::fromStdString("Top " + to_string(i+1) + ": Energy"));
                        break;
                    }
                    case 1: {
                        plots.back()->setWindowTitle(QString::fromStdString("Top " + to_string(i+1) + ": LAz"));
                        break;
                    }
                    case 2: {
                        plots.back()->setWindowTitle(QString::fromStdString("Top " + to_string(i+1) + ": LA3"));
                        break;
                    }
                    case 3: {
                        plots.back()->setWindowTitle(QString::fromStdString("Top " + to_string(i+1) + ": a · (ω x L)"));
                        break;
                    }
                }





            }
        }
    }
}
// ======================================================================
GLWindow::~GLWindow() {
    delete timer;
    delete chronometre;
}
// ======================================================================
void GLWindow::initializeGL()
{

    scene->initialize();
    for (auto support : supports) { //so that the first point in text and file output is at time 0, to recover initial conditions
        support->dessine(time, scene->system);
    }
    chronometre->start();

    for(std::unique_ptr<PlotWindow>& plot : plots) {
        plot->showNormal();
        plot->raise();
        plot->activateWindow();
    }
}
//standard Qt OpenGL
// ======================================================================
void GLWindow::resizeGL(int width, int height)
{
    scene->resize(width, height);

    glViewport( 0, 0, devicePixelRatio()*width, devicePixelRatio()*height);
    timerTimeout();
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
    //Camera movement
    scene->deplacer(dt,up, down, forw, back, left, right);

    everySixtyTimes += 1;
    if(everySixtyTimes == 60) {
        //FPS calculations
        everySixtyTimes = 0;
        measuredFPS = 60/DeltaTs.sum();
        cout << "fps: " << measuredFPS << endl;
    }
    if(!paused) {
        time +=  dt;
        //system integration
        scene->integrateSystem(dt, integSubDiv);
        //add points to traces every 5 frames
        if(everyFiveTimes == 0) {
            scene->system.addToTraces();
            everyFiveTimes = 5;
            //plot1.replot();

            for(std::unique_ptr<PlotWindow>& plot : plots) plot->replot();
        }
        else --everyFiveTimes;
        //other places to print data to
        for (auto support : supports) {
            support->dessine(time, scene->system);
        }

        for(size_t i(0); i < plots.size(); ++i) {
            plots[i]->append(time, scene->system.getToupies()[plotIndexes[i].first]->returnIndicators()[plotIndexes[i].second]);
        }
        //plot1.append(time, scene->system.getToupies()[0]->returnIndicators()[0]);
        //plot1.repaint();
    }
    //graphics update


    update();




}

// ======================================================================
void GLWindow::pause()
{
    if(!paused) timerTimeout(); //update one last time to be as close to correct with timings as possible.
    if(paused) chronometre->start(); //restart timer if we were paused.
    paused = 1 - paused; //switch state

}
//keyPressEvents and keyReleaseEvents are handled separately for AWSD Shift Space to allow smooth camera movement.
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
        case Qt::Key_O:
            scene->zoomFactor += 0.5;
            scene->setZoomPerspectiveMatrix(width(), height());
            break;
        case Qt::Key_L:
            scene->zoomFactor = std::max(0.5, scene->zoomFactor - 0.5);
            scene->setZoomPerspectiveMatrix(width(), height());
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

//This method handles mouse movement. For the mouse not to leave the window, we have to keep it in the rectangle rect()- MouseMargins (cf GLWindow.h)
// ======================================================================
void GLWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(!CapturedMouse) return;
    if((rect()-MouseMargins).contains(mapFromGlobal(QCursor::pos()))) {
        if(!CursorSet) {

            //avoid jumping on mouse entry
            if(MouseEntry)
            {
                lastMousePosition = event->pos();
                MouseEntry = false;
                CapturedMouse = true;
                return;
            }

            // Relative movement compared to last position
            QPointF d = event->pos() - lastMousePosition;
            scene->DeltaPitchYaw(- sensitivity/scene->zoomFactor*float(d.y()), sensitivity/scene->zoomFactor*float(d.x()));

            lastMousePosition = event->pos();
            CursorSet = true;

        }
        if(CursorSet) {
            CursorSet = false;
        }
    }
    else {
        CursorSet = true;
        QCursor::setPos(mapToGlobal(QPoint(width() / 2, height() / 2))); //center cursor

        lastMousePosition = QPoint(width() / 2, height() / 2);
    }
}
void GLWindow::closeEvent(QCloseEvent *event) {
    for(auto& plot : plots) plot->deleteLater();
}
