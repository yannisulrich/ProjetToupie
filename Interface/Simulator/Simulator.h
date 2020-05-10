
#pragma once

#include <OpenGLViewer/GLWindow.h>

class Integrateur;
class Simulator {
private:
    GLWindow* glwindow;

    Scene* scene;

    int fps;
    int integSubDiv;

    bool graphics;
    std::vector<SupportADessin*> supports;

    float scaleFactor;
public:
    Systeme* system; //pointer to scene->system, so that system can be publicly modified but scene can't.
    Simulator(const bool& graphics, Integrateur* integrateur, const int& fps, const int& integSubDiv, std::vector<SupportADessin*> supports, const float& scaleFactor = 1,
              const int & screenw = 1200, const int& screenh = 800);
    int run();
};
