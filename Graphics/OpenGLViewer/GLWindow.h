/*
 * Cette classe est la fenêtre de représentation 3D. Elle est aussi responsable de recevoir les signaux des touches ou de la souris.
 * Comme élaboré plus en détail dans le commentaire dans la classe scene, le déplacement est implémenté "à la minecraft".
 * La souris est donc absorbée par la fenêtre. La touche esc permet de rendre la souris à l'utilisateur, et met sur pause la simulation.
 * Les méthodes de la classe sont celles redéfinies de QOpenGLWidget, plus de détails dans le .cc
 *
 * La fenêtre contient aussi un vecteur de pointeurs vers d'autre supports comme des fichiers ou un autre stream. Ceux-ci
 * sont donc aussi appelés en même temps que le dessin OpenGL.
 */

#pragma once
#include <QWidget>
#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QOpenGLContext>
#include <QElapsedTimer>
#include <QTime>
#include <QTimer> // Classe pour gérer le temps
#include "scene.h"
#include "Trace.h"
#include "PlotWidget.h"
class GLWindow : public QOpenGLWidget
{
Q_OBJECT

public:
    GLWindow(Scene* scene_, const int& fps, const int& integSubdiv, std::vector<SupportADessin*> supports, const float& scaleFactor, QWidget* parent = nullptr);

    ~GLWindow() override;

protected:
    void initializeGL() override; //Qt specific

private:

    // Qt specific functions for drawing and input
    void resizeGL(int width, int height)     override; //TODO: handle resize while sim. running
    void paintGL()                           override;
    void keyPressEvent(QKeyEvent* event)     override;
    void timerEvent(QTimerEvent* event)      override {};
    void keyReleaseEvent(QKeyEvent* event)   override;
    void mouseMoveEvent(QMouseEvent* event)  override;

    // Internal function that contains what happens upon triggering of timer. We do not use Qts default to easily call it manually.
    void timerTimeout();

    //pause or unpause drawing of tops
    void pause();

    Scene* scene;

    //integrator precision. Every time step dt will be integrated in steps of dt/integSubDiv, to increase precision.
    int integSubDiv;
    int fps;
    // Timer
    QTimer *timer;
    // to evolve system with precise dt
    QElapsedTimer * chronometre;
    double time = 0; //used to indicate time when printing to other text or file

    std::vector<SupportADessin*> supports; //additional drawing supports, like text output or file output


    //pour le deplacement de la souris
    QPoint lastMousePosition;
    float sensitivity = 0.0024; //mouse sensitivity
    bool CapturedMouse = true; //pour éviter un saut lors de l'entrée de la souris
    bool CursorSet = false; //wether the cursor is invisible or not

    bool paused = true; //start paused to have time to set up camera


    bool up = false, down = false, forw = false, back = false, left = false, right = false; //handles movement, when one is true there is movement in that direction

    bool MouseEntry = true; //to avoid jumping of view on mouse entry, either at start or from escaping






    QMargins MouseMargins = QMargins(50,50,50,50); //used to maintain mouse inside window

    Trace<20> DeltaTs; //a "trace" of delta t between frames, to measure average fps
    float measuredFPS;

    unsigned int everySixtyTimes = 0; //used to trigger events every 60 frames

    unsigned int TraceWriteCounter = 0; //counter used to write to traces regularly but not every frame

    PlotWidget plot1;

};

