#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "MathCore.h"

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


void MainWindow::on_pushButtonT_clicked()
{

    double omega_i = ui->doubleSpinBox_o->value();
    double theta_i = ui->doubleSpinBox_t->value();
    double mu_i = ui->doubleSpinBox_u->value();
    int integrator = ui->Integrator->currentIndex();
    switch(integrator) {
        case 0: {
            IntegrateurEulerCromer5 integ(f);
            break;
        }
        case 1: {
            IntegrateurNewmark5 integ(f, 0.001);
            break;
        }
        case 2: {
            IntegrateurRungeKutta5 integ(f);
            break;
        }
    }

    std::cout << "PushButtonT pressed with values" << std::endl;
}
