#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    int j = 1;
    char  arg0[] = "Spinning Top Simulator";
    char* argvOverride[] = { &arg0[0], NULL };
    QApplication app(j, argvOverride);
    MainWindow w;
    w.show();
    return app.exec();

}
