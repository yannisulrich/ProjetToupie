#include "mainwindow.h"

#include <QApplication>
#include "Vecteur.h"
int main(int argc, char *argv[])
{
    VecteurN v({1,2,3});
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();

}
