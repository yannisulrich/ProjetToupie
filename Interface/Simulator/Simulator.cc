
#include <QApplication>
#include <utility>
#include "Simulator.h"

Simulator::Simulator(const bool& graphics, Integrateur* integrateur, const int& fps, const int& integSubDiv, std::vector<SupportADessin*> supports):
fps(fps), integSubDiv(integSubDiv), graphics(graphics), supports(std::move(supports)) {

    if(graphics) {
        scene = new Scene(integrateur);
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
    glwindow = new GLWindow(scene, fps, integSubDiv, supports);
    glwindow->show();

    return a.exec();
}
