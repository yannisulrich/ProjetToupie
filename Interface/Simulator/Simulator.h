
#pragma once

#include <Graphics/OpenGLViewer/GLWindow.h>

class Integrateur;
class Simulator {
private:
    GLWindow* glwindow;

    Scene* scene;

    int fps;
    int integSubDiv;
    int traceFrequency;

    bool graphics;
    std::vector<SupportADessin*> supports;
    bool running = false;

    float scaleFactor;
public:
    Systeme* system; //pointer to scene->system, so that system can be publicly modified but scene can't.
    Simulator(const bool& graphics, Integrateur* integrateur, const int& fps, const int& integSubDiv, std::vector<SupportADessin*> supports, const float& scaleFactor = 1, const QString& tablepath = "",
              const int & screenw = 1200, const int& screenh = 800, const int& traceFrequency = 5);

    int runNewApp();
    void runInApp();
};
