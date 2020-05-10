
#include <QApplication>
#include <utility>
#include "Simulator.h"

Simulator::Simulator(const bool& graphics, Integrateur* integrateur, const int& fps, const int& integSubDiv, std::vector<SupportADessin*> supports, const float& scaleFactor,
                            const int & screenw, const int& screenh):
fps(fps), integSubDiv(integSubDiv), graphics(graphics), supports(std::move(supports)), scaleFactor(scaleFactor) {

    if(graphics) {
        scene = new Scene(integrateur, screenw, screenh);
        system = &scene->system;
    }
}

int Simulator::run() {
    char  arg0[] = "Spinning Top Simulator";
    char* argv[] = { &arg0[0], NULL };
    int   argc   = (int)(sizeof(argv) / sizeof(argv[0])) - 1;

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setMajorVersion(4);
    format.setMinorVersion(1);
    format.setProfile(QSurfaceFormat::CoreProfile);

    QSurfaceFormat::setDefaultFormat(format);



    QApplication a(argc, &argv[0]);
    glwindow = new GLWindow(scene, fps, integSubDiv, supports, scaleFactor);
    glwindow->show();

    return a.exec();
}
