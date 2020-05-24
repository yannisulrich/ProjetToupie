

#include <algorithm>
#include "PlotWindow.h"

#include "mainwindow.h"
#include "ui_plotwindow.h"

PlotWindow::PlotWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::PlotWindow),
        plot(0)
{
    setWindowFlags(Qt::Tool);
    ui->setupUi(this);

    plot = new QCustomPlot(this);

    setCentralWidget(plot);

    // create graph and assign data to it:
    plot->addGraph();
    plot->graph(0)->setData(t, y);
    // give the axes some labels:
    plot->xAxis->setLabel("t");
    plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    plot->xAxis->setRange(0, 1);
    plot->yAxis->setRange(0, 1);
    plot->replot();
}

PlotWindow::~PlotWindow()
{
    delete ui;
}


void PlotWindow::append(const double& tin, const double& yin) {
    if(yin > maxY) {
        maxY = yin;
        plot->yAxis->setRange(minY - (maxY-minY)*0.05, maxY+(maxY-minY)*0.05);
    }
    if(yin < minY) {
        minY = yin;
        plot->yAxis->setRange(minY - (maxY-minY)*0.05, maxY+(maxY-minY)*0.05);
        //chart->axes(Qt::Vertical).back()->setRange(minY, 1.05*maxY);
    }
    if(tin > maxT) {
        maxT = tin;
        plot->xAxis->setRange(0, std::max(1.0 ,maxT));
        //chart->axes(Qt::Vertical).back()->setRange(minY, 1.05*maxY);
    }
    plot->graph(0)->addData(tin, yin);
    //series->append(tin, y);
    //chart->axes(Qt::Horizontal).back()->setRange(0, maxX);


}
void PlotWindow::replot() {
    plot->replot();
}





