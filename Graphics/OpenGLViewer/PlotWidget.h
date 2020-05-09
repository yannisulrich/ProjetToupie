/*
 * Classe qui fait les graphiques des indicateurs en direct.
 */

#pragma once

#include <QtCharts>

class PlotWidget {
private:
    double maxY = 0, minY = 0; //ceci sert à automatiquement adapter l'échelle du graphe
    double maxX = 0;
    QLineSeries *series; //les points
    QChart *chart; //le graphique
    QChartView * chartView; //le Widget pour le tout
public:
    PlotWidget();
    void append(const double&, const double&); //ajoute un point
    void setTitle(const QString&);  //fixe le titre, doit être fait avant show
    void show();    //affiche la fenêtre
    void repaint(); //"refresh", après avoir changé les données.
};


