/*
 * Classe qui fait les graphiques des indicateurs en direct.
 */
//#include " QCustomPlot/qcustomplot.h"
#include "qcustomplot.h"

#pragma once


namespace Ui {
    class PlotWindow;
}

class PlotWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();
    void append(const double&, const double&);
    void replot();
private:
    double minY = 0, maxY = 0, maxT = 0;
    QVector<double> t, y;
    Ui::PlotWindow *ui;
    QCustomPlot *plot;
};

    ////ajoute un point
    //void setTitle(const QString&);  //fixe le titre, doit être fait avant show
    //void show();    //affiche la fenêtre



