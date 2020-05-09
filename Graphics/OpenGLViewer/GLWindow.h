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
    void initializeGL() override;

private:

    // Méthodes de gestion d'évènements
    void resizeGL(int width, int height)     override;
    void paintGL()                           override;
    void keyPressEvent(QKeyEvent* event)     override;
    void timerEvent(QTimerEvent* event)      override {};
    void keyReleaseEvent(QKeyEvent* event)   override;
    void mouseMoveEvent(QMouseEvent* event)  override;

    // Méthodes de gestion interne
    void timerTimeout();
    void pause();

    Scene* scene;

    //integrator precision. Every time step dt will be integrated in steps of dt/integSubDiv, to increase precision.
    int integSubDiv;
    int fps;
    // Timer
    QTimer *timer;
    // pour faire évoluer les objets avec le bon "dt"
    QElapsedTimer * chronometre;
    double time = 0; //utilisé pour les autres supports
    double prevTime = 0; //utilisé pour la mesure des FPS
    // objets à dessiner, faire évoluer

    std::vector<SupportADessin*> supports; //supports supplémentaires (fichiers, texte, ...autre chose?)


    //deplacement:
    QPoint lastMousePosition;

    bool CapturedMouse = true;
    bool paused = true; //start paused to have time to set up camera

    bool up = false, down = false, forw = false, back = false, left = false, right = false; //handles movement, when one is true there is movement in that direction

    bool MouseEntry = true; //to avoid jumping of view on mouse entry, either at start or from escaping

    float sensitivity = 0.0024;


    bool CursorSet = false;

    QMargins MouseMargins = QMargins(50,50,50,50); //sert à garder la souris en place, cf .cc

    Trace<20> DeltaTs;
    float measuredFPS;

    unsigned int everySixtyTimes = 0;
    unsigned int TraceWriteCounter = 0;

    PlotWidget plot1;

};

