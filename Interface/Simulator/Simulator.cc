
#include <QApplication>
#include <utility>
#include "Simulator.h"

Simulator::Simulator(const bool& graphics, Integrateur* integrateur, const int& fps, const int& integSubDiv, std::vector<SupportADessin*> supports, const float& scaleFactor,
        const QString& tablepath, const int & screenw, const int& screenh, const int& traceFrequency):
fps(fps), integSubDiv(integSubDiv), traceFrequency(traceFrequency), graphics(graphics), supports(std::move(supports)), scaleFactor(scaleFactor) {
    if(graphics) {
        scene = new Scene(integrateur, screenw, screenh, 600/traceFrequency, tablepath);
        system = &scene->system;
    }
}

int Simulator::runNewApp() {
    if(running) {
        return -1;
    }
    char  arg0[] = "Spinning Top Simulator";
    char* argv[] = { &arg0[0], NULL };
    int   argc   = (int)(sizeof(argv) / sizeof(argv[0])) - 1;

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setMajorVersion(4);
    format.setMinorVersion(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    QApplication a(argc, &argv[0]);
    glwindow = new GLWindow(scene, fps, integSubDiv, supports, scaleFactor, QApplication::desktop()->devicePixelRatio(), traceFrequency);
    glwindow->show();

    running = true;
    return a.exec();

}
void Simulator::runInApp() {
    if(running) {
        return;
    }
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setMajorVersion(4);
    format.setMinorVersion(1);
    format.setProfile(QSurfaceFormat::CoreProfile);

    QSurfaceFormat::setDefaultFormat(format);

    glwindow = new GLWindow(scene, fps, integSubDiv, supports, scaleFactor, QApplication::desktop()->devicePixelRatio(), traceFrequency);
    glwindow->showMaximized();
    running = true;


}

