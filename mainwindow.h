#pragma once

#include <iostream>
#include <QMainWindow>
#include "Simulator/Simulator.h"
#include "Graphics/FileViewer/FileViewer.h"
#include "XMLReader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots: //events for Qt. All activate when what their name says happens :)
    void on_pushButtonLaunch_clicked();
    void on_LogFileBrowser_clicked();
    void on_TableModelBrowser_clicked();
    void on_TopModelBrowser_clicked();
    void on_helpButton_clicked();
    void on_TopSelection_currentIndexChanged(int);
    void on_Integrator_currentIndexChanged(int);
    void on_pushButton_loadconfig_clicked();
    void on_pushButton_saveconfig_clicked();
private:
    Ui::MainWindow *ui;

    Integrateur* integrator;
    Simulator* simulator;
    FileViewer* fileviewer;
    QString logpath = "";
    QString tablemodelpathinput = "";
    QString topmodelpathinput = "";
    std::ofstream* logfile;

    XMLReader* xmlaccess;
    QFile* configfile;
};

