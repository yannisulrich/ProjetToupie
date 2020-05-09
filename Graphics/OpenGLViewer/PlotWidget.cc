
#include "PlotWidget.h"

PlotWidget::PlotWidget() {
    series = new QLineSeries();

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setRange(0, maxX);
    chart->axes(Qt::Vertical).back()->setRange(minY, maxY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,300);

}
void PlotWidget::append(const double& x, const double& y) {
    if(y > maxY) maxY = y;
    if(y < minY) {
        minY = y;
        chart->axes(Qt::Vertical).back()->setRange(minY, 1.05*maxY);
    }
    if(x > maxX) {
        maxX = x;
        chart->axes(Qt::Vertical).back()->setRange(minY, 1.05*maxY);
    }
    series->append(x, y);
    chart->axes(Qt::Horizontal).back()->setRange(0, maxX);

}
void PlotWidget::setTitle(const QString& title) {
    chart->setTitle(title);
}
void PlotWidget::show() {
    chartView->show();
}
void PlotWidget::repaint() {
    chartView->repaint();
}






