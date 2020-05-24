#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <MathCore/Integrateurs/All_Integrateurs.h>
#include "Simulator/Simulator.h"
#include "../../../../../../../usr/local/Qt-5.14.2/include/QtWidgets/QtWidgets"
#include "../../../../../../../usr/local/Qt-5.14.2/include/QtCore/qnamespace.h"

using namespace std;
//#include "MathCore/MathCore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    view = new QGraphicsView(scene);
    view->setRenderHints(QPainter::Antialiasing
                         | QPainter::SmoothPixmapTransform
                         | QPainter::TextAntialiasing);
    view->setWindowFlags(Qt::Popup);
    view->setFixedSize(QSize(1200, 650));
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-view->width()) / 2;
    int y = (screenGeometry.height()-view->height()) / 2;
    view->move(x, y);
    QResource helpimage("://HelpGraphic.png");
    scene->addItem(new QGraphicsPixmapItem(QPixmap(helpimage.absoluteFilePath()).scaled(view->width(), view->height(), Qt::KeepAspectRatio)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LogFileBrowser_clicked() {

    filepath = QFileDialog::getOpenFileName(this,
                                            tr("Choose File"), "",
                                            tr("Text Files (*.txt *.log);;All Files (*)"));

    ui->pathToLog->setText(filepath);
    if(!filepath.isEmpty()) ui->Filecheckbox->setChecked(true);
}
void MainWindow::on_pushButtonLaunch_clicked()
{
    if(tablemodelpath.isEmpty()) {
        auto noTableModelInfo = new QMessageBox(QMessageBox::NoIcon, "No table model selected",
                                                "Please select a model for the table. You can choose the standard one shipped with the application.");
        noTableModelInfo->addButton("Ok", QMessageBox::AcceptRole);
        noTableModelInfo->QDialog::setWindowTitle("No table model selected");
        noTableModelInfo->setTextInteractionFlags(Qt::NoTextInteraction);
        noTableModelInfo->exec();
        return;
    }
    if(topmodelpath.isEmpty()) {
        auto noTopModelInfo = new QMessageBox(QMessageBox::NoIcon, "No top model selected",
                                              "Please select a model for the top. You can choose the appropriate standard one shipped with the application.");
        noTopModelInfo->addButton("Ok", QMessageBox::AcceptRole);
        noTopModelInfo->QDialog::setWindowTitle("No top model selected");
        noTopModelInfo->setTextInteractionFlags(Qt::NoTextInteraction);
        noTopModelInfo->exec();
        return;
    }


    switch (ui->Integrator->currentIndex()) {
    case 0: integrator = new IntegrateurEulerCromer();
    case 1: integrator = new IntegrateurNewmark5(ui->doubleSpinBox_Integrator->value());
    case 2: integrator = new IntegrateurRungeKutta5();
    }

    if(ui->Filecheckbox->isChecked() and !filepath.isEmpty()) {
        file = new ofstream(ui->pathToLog->text().toUtf8(), ios::out);
        fileviewer = new FileViewer(*file);
        simulator = new Simulator(true, integrator, ui->spinBox_FPS->value(), ui->spinBox_IntegPrec->value(), {fileviewer}, ui->doubleSpinBox_modelScale->value());
    }
    else {
        simulator = new Simulator(true, integrator, ui->spinBox_FPS->value(), ui->spinBox_IntegPrec->value(), {}, ui->doubleSpinBox_modelScale->value(), tablemodelpath);

    }
    Vecteur5 P(ui->doubleSpinBox_theta->value(), ui->doubleSpinBox_psi->value(), ui->doubleSpinBox_phi->value(), ui->doubleSpinBox_x->value(), ui->doubleSpinBox_y->value());
    Vecteur5 P_dot(ui->doubleSpinBox_thetadot->value(), ui->doubleSpinBox_psidot->value(), ui->doubleSpinBox_phidot->value(), ui->doubleSpinBox_xdot->value(), ui->doubleSpinBox_ydot->value());
    switch (ui->TopSelection->currentIndex()) {
        case 0: {
            simulator->system->addSymCone(P, P_dot, ui->doubleSpinBox_C2->value(),ui->doubleSpinBox_C1->value(),ui->doubleSpinBox_m->value(), topmodelpath);
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
            simulator->system->addTippeTopRolls(P, P_dot, ui->doubleSpinBox_C1->value(),ui->doubleSpinBox_C2->value(),ui->doubleSpinBox_m->value(), topmodelpath);
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
            simulator->system->addTippeTopFriction(P, P_dot, ui->doubleSpinBox_C1->value(),ui->doubleSpinBox_C2->value(),ui->doubleSpinBox_mu->value(), ui->doubleSpinBox_m->value(), topmodelpath);
            break;
        }
        case 3: {
            simulator->system->addSymConeGlisse(P, P_dot, ui->doubleSpinBox_C1->value(),ui->doubleSpinBox_C2->value(),ui->doubleSpinBox_m->value(),ui->doubleSpinBox_mu->value(), topmodelpath);
            break;
        }
    }
    simulator->system->setPlotsForTop(0, ui->checkbox_Energyplot->isChecked(), ui->checkbox_Laz->isChecked(), ui->checkbox_LA3->isChecked(), ui->checkbox_awL->isChecked());


    simulator->runInApp();
}

void MainWindow::on_TopSelection_currentIndexChanged(int index) {
    switch (index) {
        case 0: {
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->PhysParam3->setText("L");
            ui->PhysParam4->setEnabled(false);
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->Integrator->setEnabled(true);
            break;
        }
        case 1: {
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->PhysParam4->setEnabled(false);
            ui->PhysParam3->setText("h");
            ui->doubleSpinBox_mu->setEnabled(false);
            ui->Integrator->setEnabled(true);
            break;
        }
        case 2: {
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->PhysParam3->setText("ε");
            ui->PhysParam4->setEnabled(true);
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->Integrator->setEnabled(false);
            break;
        }
        case 3: {
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->PhysParam3->setText("L");
            ui->PhysParam4->setEnabled(true);
            ui->doubleSpinBox_mu->setEnabled(true);
            ui->Integrator->setEnabled(false);
            break;
        }
    }
}
void MainWindow::on_Integrator_currentIndexChanged(int index) {
    cout << "hey" << endl;
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
    tablemodelpath = QFileDialog::getOpenFileName(this,
                                            tr("Choose File"), "",
                                            tr("3D Model (*.dae *.3DS *.STL)"));

    ui->pathToTableModel->setText(tablemodelpath);
}

void MainWindow::on_TopModelBrowser_clicked() {
    topmodelpath = QFileDialog::getOpenFileName(this,
                                                  tr("Choose File"), "",
                                                  tr("3D Model (*.dae *.3DS *.STL)"));

    ui->pathToTopModel->setText(topmodelpath);
}

void MainWindow::on_helpButton_clicked() {

    //scene->addItem(new QGraphicsSvgItem("/Users/yannis/Desktop/EPFL/ICC2/projet/result.svg"));
    view->show();
}
