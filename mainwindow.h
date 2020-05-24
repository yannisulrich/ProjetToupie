#pragma once

#include <iostream>
#include <QMainWindow>
#include "Simulator/Simulator.h"
#include "Graphics/FileViewer/FileViewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButtonLaunch_clicked();
    void on_LogFileBrowser_clicked();
    void on_TableModelBrowser_clicked();
    void on_TopModelBrowser_clicked();
    void on_helpButton_clicked();
    void on_TopSelection_currentIndexChanged(int);
    void on_Integrator_currentIndexChanged(int);

private:
    Ui::MainWindow *ui;

    Integrateur* integrator;
    Simulator* simulator;
    FileViewer* fileviewer;
    QString filepath = "";
    QString tablemodelpath = "";
    QString topmodelpath = "";
    std::ofstream* file;

    QGraphicsScene* scene;
    QGraphicsView* view;
};

