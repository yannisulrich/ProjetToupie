#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <MathCore/Integrateurs/All_Integrateurs.h>
#include "Simulator/Simulator.h"
#include <QDesktopServices>
#include <QDir>
#include <QFileInfo>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool fileExists(const QString& path) {
    QFileInfo check_file(path);
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

void MainWindow::on_LogFileBrowser_clicked() {

    logpath = QFileDialog::getOpenFileName(this,
                                           tr("Choose File"), "",
                                           tr("Text Files (*.csv *.log *.txt);;All Files (*)"));

    ui->pathToLog->setText(logpath);
    if(!logpath.isEmpty()) ui->Filecheckbox->setChecked(true);
}
void MainWindow::on_pushButtonLaunch_clicked()
{


    QString usedTablemodelPath;
    if(ui->comboBox_tablemodel->currentIndex() == 0) usedTablemodelPath =
            QApplication::applicationDirPath().left(QApplication::applicationDirPath().lastIndexOf(QChar('/'))) + "/Resources/Models/tabledefault.dae";
    else {
        if(!fileExists(tablemodelpathinput)) {
            auto tablemodelNotFound = new QMessageBox(QMessageBox::NoIcon, "File not found",
                                                      "The table model path was not found on this machine.");
            tablemodelNotFound->addButton("Ok", QMessageBox::AcceptRole);
            tablemodelNotFound->QDialog::setWindowTitle("File not found");
            tablemodelNotFound->setTextInteractionFlags(Qt::NoTextInteraction);
            tablemodelNotFound->exec();
            return;
        }
        usedTablemodelPath = tablemodelpathinput;
    }


    QString usedTopmodelPath;
    if(ui->comboBox_topmodel->currentIndex() == 0) usedTopmodelPath =
            QApplication::applicationDirPath().left(QApplication::applicationDirPath().lastIndexOf(QChar('/'))) + "/Resources/Models/cone.dae";
    else if(ui->comboBox_topmodel->currentIndex() == 1) usedTopmodelPath =
            QApplication::applicationDirPath().left(QApplication::applicationDirPath().lastIndexOf(QChar('/'))) +"/Resources/Models/tippetophollow.DAE";
    else {
        if(!fileExists(topmodelpathinput)) {
            auto tablemodelNotFound = new QMessageBox(QMessageBox::NoIcon, "File not found",
                                                      "The top model path was not found on this machine.");
            tablemodelNotFound->addButton("Ok", QMessageBox::AcceptRole);
            tablemodelNotFound->QDialog::setWindowTitle("File not found");
            tablemodelNotFound->setTextInteractionFlags(Qt::NoTextInteraction);
            tablemodelNotFound->exec();
            return;
        }
        usedTopmodelPath = topmodelpathinput;
    }

    switch (ui->Integrator->currentIndex()) {
    case 0: integrator = new IntegrateurEulerCromer();
    case 1: integrator = new IntegrateurNewmark5(ui->doubleSpinBox_Integrator->value());
    case 2: integrator = new IntegrateurRungeKutta5();
    }

    if(ui->Filecheckbox->isChecked() and !logpath.isEmpty()) {
        logfile = new ofstream(ui->pathToLog->text().toUtf8(), ios::out);
        fileviewer = new FileViewer(*logfile);
        simulator = new Simulator(true, integrator, ui->spinBox_FPS->value(), ui->spinBox_IntegPrec->value(), {fileviewer}, (float) ui->doubleSpinBox_modelScale->value(), usedTablemodelPath);
    }
    else {
        simulator = new Simulator(true, integrator, ui->spinBox_FPS->value(), ui->spinBox_IntegPrec->value(), {}, (float) ui->doubleSpinBox_modelScale->value(), usedTablemodelPath);

    }
    Vecteur5 P(ui->doubleSpinBox_theta->value(), ui->doubleSpinBox_psi->value(), ui->doubleSpinBox_phi->value(), ui->doubleSpinBox_x->value(), ui->doubleSpinBox_y->value());
    Vecteur5 P_dot(ui->doubleSpinBox_thetadot->value(), ui->doubleSpinBox_psidot->value(), ui->doubleSpinBox_phidot->value(), ui->doubleSpinBox_xdot->value(), ui->doubleSpinBox_ydot->value());


    switch (ui->TopSelection->currentIndex()) {
        case 0: {
            simulator->system->addSymCone(P, P_dot, ui->doubleSpinBox_C2->value(), ui->doubleSpinBox_C1->value(), ui->doubleSpinBox_m->value(), usedTopmodelPath);
             break;
        }
        case 1: {
            if(ui->doubleSpinBox_C2->value() >= ui->doubleSpinBox_C1->value()) {
                auto WrongParameterChoice = new QMessageBox(QMessageBox::NoIcon, "Incompatible parameters",
                                                      "Please choose h smaller than R.");
                WrongParameterChoice->addButton("Ok", QMessageBox::AcceptRole);
                WrongParameterChoice->QDialog::setWindowTitle("No top model selected");
                WrongParameterChoice->setTextInteractionFlags(Qt::NoTextInteraction);
                WrongParameterChoice->exec();
                return;
            }
            simulator->system->addTippeTopRolls(P, P_dot, ui->doubleSpinBox_C1->value(), ui->doubleSpinBox_C2->value(), ui->doubleSpinBox_m->value(), usedTopmodelPath);
            break;
        }
        case 2: {
            if(ui->doubleSpinBox_C2->value() >= ui->doubleSpinBox_C1->value()) {
                auto WrongParameterChoice = new QMessageBox(QMessageBox::NoIcon, "Incompatible parameters",
                                                            "Please choose ε smaller than R.");
                WrongParameterChoice->addButton("Ok", QMessageBox::AcceptRole);
                WrongParameterChoice->QDialog::setWindowTitle("No top model selected");
                WrongParameterChoice->setTextInteractionFlags(Qt::NoTextInteraction);
                WrongParameterChoice->exec();
                return;
            }
            if(P[0] == 0) P[0] = 0.0001;
            simulator->system->addTippeTopFriction(P, P_dot, ui->doubleSpinBox_C1->value(), ui->doubleSpinBox_C2->value(), ui->doubleSpinBox_mu->value(), ui->doubleSpinBox_m->value(), usedTopmodelPath);
            break;
        }
        case 3: {
            simulator->system->addSymConeGlisse(P, P_dot, ui->doubleSpinBox_C1->value(), ui->doubleSpinBox_C2->value(), ui->doubleSpinBox_m->value(), ui->doubleSpinBox_mu->value(), usedTopmodelPath);
            break;
        }
    }
    simulator->system->setPlotsForTop(0, ui->checkbox_Energyplot->isChecked(), ui->checkbox_Laz->isChecked(), ui->checkbox_LA3->isChecked(), ui->checkbox_awL->isChecked());


    simulator->runInApp();
}

void MainWindow::on_TopSelection_currentIndexChanged(int index) {
    //Suivant la toupie, on active différents paramètres.
    switch (index) {
        case 0: {
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->PhysParam3->setText("L");
            ui->PhysParam4->setEnabled(false);
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->Integrator->setEnabled(true);
            if(ui->comboBox_topmodel->currentIndex() != 2) ui->comboBox_topmodel->setCurrentIndex(0);
            break;
        }
        case 1: {
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->PhysParam4->setEnabled(false);
            ui->PhysParam3->setText("h");
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->Integrator->setEnabled(true);
            if(ui->comboBox_topmodel->currentIndex() != 2) ui->comboBox_topmodel->setCurrentIndex(1);
            break;
        }
        case 2: {
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->PhysParam3->setText("ε");
            ui->PhysParam4->setEnabled(true);
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->Integrator->setEnabled(false);
            if(ui->comboBox_topmodel->currentIndex() != 2) ui->comboBox_topmodel->setCurrentIndex(1);
            break;
        }
        case 3: {
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->PhysParam3->setText("L");
            ui->PhysParam4->setEnabled(true);
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->Integrator->setEnabled(false);
            if(ui->comboBox_topmodel->currentIndex() != 2) ui->comboBox_topmodel->setCurrentIndex(0);
            break;
        }
    }
}
void MainWindow::on_Integrator_currentIndexChanged(int index) {
    switch (index) {
        case 0: {
            ui->doubleSpinBox_Integrator->setEnabled(false);
            ui->label_IntegratorE->setEnabled(false);
            break;
        }
        case 1: {
            ui->doubleSpinBox_Integrator->setEnabled(true);
            ui->label_IntegratorE->setEnabled(true);
            break;
        }
        case 2: {
            ui->doubleSpinBox_Integrator->setEnabled(false);
            ui->label_IntegratorE->setEnabled(false);
            break;
        }
    }
}

void MainWindow::on_TableModelBrowser_clicked() {
    tablemodelpathinput = QFileDialog::getOpenFileName(this,
                                                       tr("Choose File"), "",
                                                       tr("3D Model (*.dae *.3DS *.STL)"));

    ui->pathToTableModel->setText(tablemodelpathinput);
    ui->comboBox_tablemodel->setCurrentIndex(1);
}

void MainWindow::on_TopModelBrowser_clicked() {
    topmodelpathinput = QFileDialog::getOpenFileName(this,
                                                     tr("Choose File"), "",
                                                     tr("3D Model (*.dae *.3DS *.STL)"));

    ui->pathToTopModel->setText(topmodelpathinput);
    ui->comboBox_topmodel->setCurrentIndex(2);
}

void MainWindow::on_helpButton_clicked() {
    QDesktopServices::openUrl(QUrl("https://github.com/yannisulrich/ProjetToupie/#projet-de-simulation-dune-Toupie"));
}

void MainWindow::on_pushButton_loadconfig_clicked() {
    QString configpath = QFileDialog::getOpenFileName(this,
                                           tr("Choose File"), "",
                                           tr("XML files (*.xml)"));

    configfile = new QFile(configpath);
    if(!configfile->open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read config file" << configfile->errorString();
    }
    xmlaccess = new XMLReader(configfile);

    xmlaccess->readFile();

    const QString xmlTop = xmlaccess->readString("top");

    if (xmlTop == "Simple fixed cone") ui->TopSelection->setCurrentIndex(0);
    if (xmlTop == "Rolling tippe top") ui->TopSelection->setCurrentIndex(1);
    if (xmlTop == "Slipping tippe top") ui->TopSelection->setCurrentIndex(2);
    if (xmlTop == "Slipping cone") ui->TopSelection->setCurrentIndex(3);

    const QString xmlIntegrator = xmlaccess->readString("integrator");

    if (xmlIntegrator == "Euler-Cromer") ui->Integrator->setCurrentIndex(0);
    if (xmlIntegrator == "Newmark") ui->Integrator->setCurrentIndex(1);
    if (xmlIntegrator == "Runge-Kutta order 4") ui->Integrator->setCurrentIndex(2);

    const QString xmlTableModel = xmlaccess->readString("tablemodelpath");
    if (xmlTableModel == "default") ui->comboBox_tablemodel->setCurrentIndex(0);
    else {
        ui->comboBox_tablemodel->setCurrentIndex(1);
        ui->pathToTableModel->setText(xmlTableModel);
        tablemodelpathinput = xmlTableModel;
    }

    const QString xmlTopModel = xmlaccess->readString("topmodelpath");
    if (xmlTopModel == "Cone") ui->comboBox_topmodel->setCurrentIndex(0);
    else if (xmlTopModel == "Tippe Top") ui->comboBox_topmodel->setCurrentIndex(1);
    else {
        ui->comboBox_topmodel->setCurrentIndex(2);
        ui->pathToTopModel->setText(xmlTopModel);
        topmodelpathinput = xmlTopModel;
    }

    ui->doubleSpinBox_Integrator->setValue(xmlaccess->readValue("integratore"));
    ui->doubleSpinBox_theta->setValue(xmlaccess->readValue("theta"));
    ui->doubleSpinBox_psi->setValue(xmlaccess->readValue("psi"));
    ui->doubleSpinBox_phi->setValue(xmlaccess->readValue("phi"));
    ui->doubleSpinBox_x->setValue(xmlaccess->readValue("x"));
    ui->doubleSpinBox_y->setValue(xmlaccess->readValue("y"));

    ui->doubleSpinBox_thetadot->setValue(xmlaccess->readValue("thetadot"));
    ui->doubleSpinBox_psidot->setValue(xmlaccess->readValue("psidot"));
    ui->doubleSpinBox_phidot->setValue(xmlaccess->readValue("phidot"));
    ui->doubleSpinBox_xdot->setValue(xmlaccess->readValue("xdot"));
    ui->doubleSpinBox_ydot->setValue(xmlaccess->readValue("ydot"));

    ui->doubleSpinBox_m->setValue(xmlaccess->readValue("m"));
    ui->doubleSpinBox_C1->setValue(xmlaccess->readValue("R"));
    ui->doubleSpinBox_C2->setValue(xmlaccess->readValue("secondaryLength"));
    ui->doubleSpinBox_mu->setValue(xmlaccess->readValue("mu"));

    ui->doubleSpinBox_modelScale->setValue(xmlaccess->readValue("modelScale"));
    ui->spinBox_FPS->setValue((int)xmlaccess->readValue("FPStarget"));
    ui->spinBox_IntegPrec->setValue((int)xmlaccess->readValue("IntegPrec"));

    configfile->close();
}
void MainWindow::on_pushButton_saveconfig_clicked() {
    QString configname = QFileDialog::getSaveFileName(this,
                                                    tr("Save Xml"), ".",
                                                    tr("Xml files (*.xml)"));

    QFile configWritefile(configname);
    configWritefile.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&configWritefile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("root");

    xmlWriter.writeStartElement("strparameters");


    if(ui->TopSelection->currentIndex() == 0)
        xmlWriter.writeTextElement("top","Simple fixed cone");
    if(ui->TopSelection->currentIndex() == 1)
        xmlWriter.writeTextElement("top","Rolling tippe top");
    if(ui->TopSelection->currentIndex() == 2)
        xmlWriter.writeTextElement("top","Slipping tippe top");
    if(ui->TopSelection->currentIndex() == 3)
        xmlWriter.writeTextElement("top","Slipping cone");

    if(ui->Integrator->currentIndex() == 0)
        xmlWriter.writeTextElement("integrator","Euler-Cromer");
    if(ui->Integrator->currentIndex() == 1)
        xmlWriter.writeTextElement("integrator","Newmark");
    if(ui->Integrator->currentIndex() == 2)
        xmlWriter.writeTextElement("integrator","Runge-Kutta order 4");

    if(ui->comboBox_tablemodel->currentIndex() == 0)
        xmlWriter.writeTextElement("tablemodelpath","default");
    else xmlWriter.writeTextElement("tablemodelpath", tablemodelpathinput);

    if(ui->comboBox_topmodel->currentIndex() == 0)
        xmlWriter.writeTextElement("topmodelpath","Cone");
    else if(ui->comboBox_topmodel->currentIndex() == 1)
        xmlWriter.writeTextElement("topmodelpath","Tippe Top");
    else xmlWriter.writeTextElement("topmodelpath", topmodelpathinput);

    xmlWriter.writeEndElement(); //end strparameters

    xmlWriter.writeStartElement("numparameters");

    xmlWriter.writeTextElement("integratore", QString::number(ui->doubleSpinBox_Integrator->value()));

    xmlWriter.writeTextElement("theta", QString::number(ui->doubleSpinBox_theta->value()));
    xmlWriter.writeTextElement("psi", QString::number(ui->doubleSpinBox_psi->value()));
    xmlWriter.writeTextElement("phi", QString::number(ui->doubleSpinBox_phi->value()));
    xmlWriter.writeTextElement("x", QString::number(ui->doubleSpinBox_x->value()));
    xmlWriter.writeTextElement("y", QString::number(ui->doubleSpinBox_y->value()));

    xmlWriter.writeTextElement("thetadot", QString::number(ui->doubleSpinBox_thetadot->value()));
    xmlWriter.writeTextElement("psidot", QString::number(ui->doubleSpinBox_psidot->value()));
    xmlWriter.writeTextElement("phidot", QString::number(ui->doubleSpinBox_phidot->value()));
    xmlWriter.writeTextElement("xdot", QString::number(ui->doubleSpinBox_xdot->value()));
    xmlWriter.writeTextElement("ydot", QString::number(ui->doubleSpinBox_ydot->value()));

    xmlWriter.writeTextElement("m", QString::number(ui->doubleSpinBox_m->value()));
    xmlWriter.writeTextElement("R", QString::number(ui->doubleSpinBox_C1->value()));
    xmlWriter.writeTextElement("secondaryLength", QString::number(ui->doubleSpinBox_C2->value()));
    xmlWriter.writeTextElement("mu", QString::number(ui->doubleSpinBox_mu->value()));

    xmlWriter.writeTextElement("modelScale", QString::number(ui->doubleSpinBox_modelScale->value()));
    xmlWriter.writeTextElement("FPStarget", QString::number(ui->spinBox_FPS->value()));
    xmlWriter.writeTextElement("IntegPrec", QString::number(ui->spinBox_IntegPrec->value()));

    xmlWriter.writeEndDocument(); //end numparameters, then root

    configWritefile.close();

}
