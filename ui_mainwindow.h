/********************************************************************************
** Form generated from reading UI file 'mainwindowphXpAk.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWPHXPAK_H
#define MAINWINDOWPHXPAK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *Information;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *pushButton_saveconfig;
    QPushButton *pushButton_loadconfig;
    QSpacerItem *horizontalSpacer_34;
    QHBoxLayout *TopandIntegrator;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_5;
    QComboBox *TopSelection;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_4;
    QComboBox *Integrator;
    QLabel *label_IntegratorE;
    QDoubleSpinBox *doubleSpinBox_Integrator;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QComboBox *comboBox_tablemodel;
    QLineEdit *pathToTableModel;
    QPushButton *TableModelBrowser;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QComboBox *comboBox_topmodel;
    QLineEdit *pathToTopModel;
    QPushButton *TopModelBrowser;
    QLabel *label_initvalues;
    QHBoxLayout *InitialValues;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_theta;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_psi;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_phi;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_x;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_y;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *Initialdotvalues;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_thetadot;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_psidot;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_phidot;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_xdot;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_ydot;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_physparam;
    QHBoxLayout *PhysParameters;
    QSpacerItem *horizontalSpacer_21;
    QLabel *massLabel;
    QDoubleSpinBox *doubleSpinBox_m;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_22;
    QLabel *physParam2;
    QDoubleSpinBox *doubleSpinBox_C1;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer_23;
    QLabel *PhysParam3;
    QDoubleSpinBox *doubleSpinBox_C2;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_25;
    QLabel *PhysParam4;
    QDoubleSpinBox *doubleSpinBox_mu;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_advopt;
    QHBoxLayout *AdvancedOpinions;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_modelScale;
    QSpacerItem *horizontalSpacer_27;
    QLabel *label_21;
    QSpinBox *spinBox_FPS;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_22;
    QSpinBox *spinBox_IntegPrec;
    QSpacerItem *horizontalSpacer_29;
    QHBoxLayout *FileWriteLine;
    QSpacerItem *horizontalSpacer;
    QCheckBox *Filecheckbox;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkbox_Energyplot;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkbox_LA3;
    QLabel *label_plotLA3;
    QSpacerItem *horizontalSpacer_30;
    QCheckBox *checkbox_Laz;
    QLabel *label_LAz;
    QSpacerItem *horizontalSpacer_32;
    QCheckBox *checkbox_awL;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_33;
    QHBoxLayout *horizontalLayout;
    QLineEdit *pathToLog;
    QPushButton *LogFileBrowser;
    QHBoxLayout *LaunchLine;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonLaunch;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *helpButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1032, 836);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Information = new QTextBrowser(centralwidget);
        Information->setObjectName(QString::fromUtf8("Information"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Information->sizePolicy().hasHeightForWidth());
        Information->setSizePolicy(sizePolicy);
        Information->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(Information);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_31);

        pushButton_saveconfig = new QPushButton(centralwidget);
        pushButton_saveconfig->setObjectName(QString::fromUtf8("pushButton_saveconfig"));

        horizontalLayout_2->addWidget(pushButton_saveconfig);

        pushButton_loadconfig = new QPushButton(centralwidget);
        pushButton_loadconfig->setObjectName(QString::fromUtf8("pushButton_loadconfig"));

        horizontalLayout_2->addWidget(pushButton_loadconfig);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_34);


        verticalLayout->addLayout(horizontalLayout_2);

        TopandIntegrator = new QHBoxLayout();
        TopandIntegrator->setObjectName(QString::fromUtf8("TopandIntegrator"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TopandIntegrator->addItem(horizontalSpacer_10);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        TopandIntegrator->addWidget(label_5);

        TopSelection = new QComboBox(centralwidget);
        TopSelection->addItem(QString());
        TopSelection->addItem(QString());
        TopSelection->addItem(QString());
        TopSelection->addItem(QString());
        TopSelection->setObjectName(QString::fromUtf8("TopSelection"));
        TopSelection->setMinimumSize(QSize(220, 0));

        TopandIntegrator->addWidget(TopSelection);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TopandIntegrator->addItem(horizontalSpacer_12);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        TopandIntegrator->addWidget(label_4);

        Integrator = new QComboBox(centralwidget);
        Integrator->addItem(QString());
        Integrator->addItem(QString());
        Integrator->addItem(QString());
        Integrator->setObjectName(QString::fromUtf8("Integrator"));
        Integrator->setEnabled(true);
        Integrator->setMinimumSize(QSize(220, 0));

        TopandIntegrator->addWidget(Integrator);

        label_IntegratorE = new QLabel(centralwidget);
        label_IntegratorE->setObjectName(QString::fromUtf8("label_IntegratorE"));
        label_IntegratorE->setEnabled(false);

        TopandIntegrator->addWidget(label_IntegratorE);

        doubleSpinBox_Integrator = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_Integrator->setObjectName(QString::fromUtf8("doubleSpinBox_Integrator"));
        doubleSpinBox_Integrator->setEnabled(false);
        doubleSpinBox_Integrator->setMinimumSize(QSize(80, 0));
        doubleSpinBox_Integrator->setDecimals(6);
        doubleSpinBox_Integrator->setMinimum(0.000001000000000);
        doubleSpinBox_Integrator->setMaximum(1.000000000000000);
        doubleSpinBox_Integrator->setSingleStep(0.000100000000000);

        TopandIntegrator->addWidget(doubleSpinBox_Integrator);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TopandIntegrator->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(TopandIntegrator);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        comboBox_tablemodel = new QComboBox(centralwidget);
        comboBox_tablemodel->addItem(QString());
        comboBox_tablemodel->addItem(QString());
        comboBox_tablemodel->setObjectName(QString::fromUtf8("comboBox_tablemodel"));
        comboBox_tablemodel->setMinimumSize(QSize(120, 0));

        horizontalLayout_3->addWidget(comboBox_tablemodel);

        pathToTableModel = new QLineEdit(centralwidget);
        pathToTableModel->setObjectName(QString::fromUtf8("pathToTableModel"));
        pathToTableModel->setEnabled(true);
        pathToTableModel->setMinimumSize(QSize(350, 0));
        pathToTableModel->setReadOnly(true);

        horizontalLayout_3->addWidget(pathToTableModel);

        TableModelBrowser = new QPushButton(centralwidget);
        TableModelBrowser->setObjectName(QString::fromUtf8("TableModelBrowser"));

        horizontalLayout_3->addWidget(TableModelBrowser);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(80, 0));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_15);

        comboBox_topmodel = new QComboBox(centralwidget);
        comboBox_topmodel->addItem(QString());
        comboBox_topmodel->addItem(QString());
        comboBox_topmodel->addItem(QString());
        comboBox_topmodel->setObjectName(QString::fromUtf8("comboBox_topmodel"));
        comboBox_topmodel->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(comboBox_topmodel);

        pathToTopModel = new QLineEdit(centralwidget);
        pathToTopModel->setObjectName(QString::fromUtf8("pathToTopModel"));
        pathToTopModel->setEnabled(true);
        pathToTopModel->setMinimumSize(QSize(350, 0));
        pathToTopModel->setReadOnly(true);

        horizontalLayout_4->addWidget(pathToTopModel);

        TopModelBrowser = new QPushButton(centralwidget);
        TopModelBrowser->setObjectName(QString::fromUtf8("TopModelBrowser"));

        horizontalLayout_4->addWidget(TopModelBrowser);


        verticalLayout->addLayout(horizontalLayout_4);

        label_initvalues = new QLabel(centralwidget);
        label_initvalues->setObjectName(QString::fromUtf8("label_initvalues"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_initvalues->sizePolicy().hasHeightForWidth());
        label_initvalues->setSizePolicy(sizePolicy2);
        label_initvalues->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_initvalues);

        InitialValues = new QHBoxLayout();
        InitialValues->setObjectName(QString::fromUtf8("InitialValues"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialValues->addItem(horizontalSpacer_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InitialValues->addWidget(label);

        doubleSpinBox_theta = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_theta->setObjectName(QString::fromUtf8("doubleSpinBox_theta"));
        doubleSpinBox_theta->setMinimumSize(QSize(100, 0));
        doubleSpinBox_theta->setAccelerated(true);
        doubleSpinBox_theta->setDecimals(3);
        doubleSpinBox_theta->setMaximum(3.141000000000000);
        doubleSpinBox_theta->setSingleStep(0.010000000000000);

        InitialValues->addWidget(doubleSpinBox_theta);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialValues->addItem(horizontalSpacer_4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InitialValues->addWidget(label_2);

        doubleSpinBox_psi = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_psi->setObjectName(QString::fromUtf8("doubleSpinBox_psi"));
        doubleSpinBox_psi->setMinimumSize(QSize(100, 0));
        doubleSpinBox_psi->setAccelerated(true);
        doubleSpinBox_psi->setDecimals(3);
        doubleSpinBox_psi->setMaximum(6.283000000000000);
        doubleSpinBox_psi->setSingleStep(0.010000000000000);

        InitialValues->addWidget(doubleSpinBox_psi);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialValues->addItem(horizontalSpacer_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InitialValues->addWidget(label_3);

        doubleSpinBox_phi = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_phi->setObjectName(QString::fromUtf8("doubleSpinBox_phi"));
        doubleSpinBox_phi->setMinimumSize(QSize(100, 0));
        doubleSpinBox_phi->setAccelerated(true);
        doubleSpinBox_phi->setDecimals(3);
        doubleSpinBox_phi->setMaximum(6.283000000000000);
        doubleSpinBox_phi->setSingleStep(0.010000000000000);

        InitialValues->addWidget(doubleSpinBox_phi);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialValues->addItem(horizontalSpacer_2);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InitialValues->addWidget(label_7);

        doubleSpinBox_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_x->setObjectName(QString::fromUtf8("doubleSpinBox_x"));
        doubleSpinBox_x->setMinimumSize(QSize(100, 0));
        doubleSpinBox_x->setAccelerated(true);
        doubleSpinBox_x->setDecimals(3);
        doubleSpinBox_x->setMinimum(-99.998999999999995);
        doubleSpinBox_x->setMaximum(99.998999999999995);
        doubleSpinBox_x->setSingleStep(0.010000000000000);

        InitialValues->addWidget(doubleSpinBox_x);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        InitialValues->addWidget(label_16);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialValues->addItem(horizontalSpacer_13);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InitialValues->addWidget(label_8);

        doubleSpinBox_y = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_y->setObjectName(QString::fromUtf8("doubleSpinBox_y"));
        doubleSpinBox_y->setMinimumSize(QSize(100, 0));
        doubleSpinBox_y->setAccelerated(true);
        doubleSpinBox_y->setDecimals(3);
        doubleSpinBox_y->setMinimum(-99.998999999999995);
        doubleSpinBox_y->setMaximum(99.998999999999995);
        doubleSpinBox_y->setSingleStep(0.010000000000000);

        InitialValues->addWidget(doubleSpinBox_y);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        InitialValues->addWidget(label_17);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialValues->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(InitialValues);

        Initialdotvalues = new QHBoxLayout();
        Initialdotvalues->setObjectName(QString::fromUtf8("Initialdotvalues"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Initialdotvalues->addItem(horizontalSpacer_15);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Initialdotvalues->addWidget(label_9);

        doubleSpinBox_thetadot = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_thetadot->setObjectName(QString::fromUtf8("doubleSpinBox_thetadot"));
        doubleSpinBox_thetadot->setMinimumSize(QSize(100, 0));
        doubleSpinBox_thetadot->setAccelerated(true);
        doubleSpinBox_thetadot->setDecimals(3);
        doubleSpinBox_thetadot->setMinimum(-99.998999999999995);
        doubleSpinBox_thetadot->setMaximum(99.998999999999995);
        doubleSpinBox_thetadot->setSingleStep(0.010000000000000);
        doubleSpinBox_thetadot->setValue(0.000000000000000);

        Initialdotvalues->addWidget(doubleSpinBox_thetadot);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Initialdotvalues->addItem(horizontalSpacer_16);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Initialdotvalues->addWidget(label_10);

        doubleSpinBox_psidot = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_psidot->setObjectName(QString::fromUtf8("doubleSpinBox_psidot"));
        doubleSpinBox_psidot->setMinimumSize(QSize(100, 0));
        doubleSpinBox_psidot->setAccelerated(true);
        doubleSpinBox_psidot->setDecimals(3);
        doubleSpinBox_psidot->setMinimum(-99.998999999999995);
        doubleSpinBox_psidot->setMaximum(99.998999999999995);
        doubleSpinBox_psidot->setSingleStep(0.010000000000000);

        Initialdotvalues->addWidget(doubleSpinBox_psidot);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Initialdotvalues->addItem(horizontalSpacer_17);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Initialdotvalues->addWidget(label_11);

        doubleSpinBox_phidot = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_phidot->setObjectName(QString::fromUtf8("doubleSpinBox_phidot"));
        doubleSpinBox_phidot->setMinimumSize(QSize(100, 0));
        doubleSpinBox_phidot->setAccelerated(true);
        doubleSpinBox_phidot->setDecimals(3);
        doubleSpinBox_phidot->setMinimum(-499.999000000000024);
        doubleSpinBox_phidot->setMaximum(499.999000000000024);
        doubleSpinBox_phidot->setSingleStep(0.010000000000000);

        Initialdotvalues->addWidget(doubleSpinBox_phidot);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Initialdotvalues->addItem(horizontalSpacer_18);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Initialdotvalues->addWidget(label_12);

        doubleSpinBox_xdot = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_xdot->setObjectName(QString::fromUtf8("doubleSpinBox_xdot"));
        doubleSpinBox_xdot->setMinimumSize(QSize(100, 0));
        doubleSpinBox_xdot->setAccelerated(true);
        doubleSpinBox_xdot->setDecimals(3);
        doubleSpinBox_xdot->setMinimum(-99.998999999999995);
        doubleSpinBox_xdot->setMaximum(99.998999999999995);
        doubleSpinBox_xdot->setSingleStep(0.010000000000000);

        Initialdotvalues->addWidget(doubleSpinBox_xdot);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        Initialdotvalues->addWidget(label_18);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Initialdotvalues->addItem(horizontalSpacer_19);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Initialdotvalues->addWidget(label_13);

        doubleSpinBox_ydot = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ydot->setObjectName(QString::fromUtf8("doubleSpinBox_ydot"));
        doubleSpinBox_ydot->setMinimumSize(QSize(100, 0));
        doubleSpinBox_ydot->setAccelerated(true);
        doubleSpinBox_ydot->setDecimals(3);
        doubleSpinBox_ydot->setSingleStep(0.010000000000000);

        Initialdotvalues->addWidget(doubleSpinBox_ydot);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        Initialdotvalues->addWidget(label_19);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Initialdotvalues->addItem(horizontalSpacer_20);


        verticalLayout->addLayout(Initialdotvalues);

        label_physparam = new QLabel(centralwidget);
        label_physparam->setObjectName(QString::fromUtf8("label_physparam"));
        label_physparam->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_physparam->sizePolicy().hasHeightForWidth());
        label_physparam->setSizePolicy(sizePolicy2);
        label_physparam->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_physparam);

        PhysParameters = new QHBoxLayout();
        PhysParameters->setObjectName(QString::fromUtf8("PhysParameters"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PhysParameters->addItem(horizontalSpacer_21);

        massLabel = new QLabel(centralwidget);
        massLabel->setObjectName(QString::fromUtf8("massLabel"));
        massLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        PhysParameters->addWidget(massLabel);

        doubleSpinBox_m = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_m->setObjectName(QString::fromUtf8("doubleSpinBox_m"));
        doubleSpinBox_m->setMinimumSize(QSize(100, 0));
        doubleSpinBox_m->setDecimals(4);
        doubleSpinBox_m->setMinimum(0.000100000000000);
        doubleSpinBox_m->setMaximum(100000.000000000000000);

        PhysParameters->addWidget(doubleSpinBox_m);

        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        PhysParameters->addWidget(label_25);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PhysParameters->addItem(horizontalSpacer_22);

        physParam2 = new QLabel(centralwidget);
        physParam2->setObjectName(QString::fromUtf8("physParam2"));
        physParam2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        PhysParameters->addWidget(physParam2);

        doubleSpinBox_C1 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_C1->setObjectName(QString::fromUtf8("doubleSpinBox_C1"));
        doubleSpinBox_C1->setMinimumSize(QSize(100, 0));
        doubleSpinBox_C1->setAccelerated(true);
        doubleSpinBox_C1->setDecimals(4);
        doubleSpinBox_C1->setMinimum(0.000000000000000);
        doubleSpinBox_C1->setSingleStep(0.100000000000000);
        doubleSpinBox_C1->setValue(0.000000000000000);

        PhysParameters->addWidget(doubleSpinBox_C1);

        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        PhysParameters->addWidget(label_23);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PhysParameters->addItem(horizontalSpacer_23);

        PhysParam3 = new QLabel(centralwidget);
        PhysParam3->setObjectName(QString::fromUtf8("PhysParam3"));
        PhysParam3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        PhysParameters->addWidget(PhysParam3);

        doubleSpinBox_C2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_C2->setObjectName(QString::fromUtf8("doubleSpinBox_C2"));
        doubleSpinBox_C2->setMinimumSize(QSize(100, 0));
        doubleSpinBox_C2->setDecimals(4);
        doubleSpinBox_C2->setMinimum(0.000000000000000);
        doubleSpinBox_C2->setValue(0.000000000000000);

        PhysParameters->addWidget(doubleSpinBox_C2);

        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        PhysParameters->addWidget(label_24);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PhysParameters->addItem(horizontalSpacer_25);

        PhysParam4 = new QLabel(centralwidget);
        PhysParam4->setObjectName(QString::fromUtf8("PhysParam4"));
        PhysParam4->setEnabled(false);
        PhysParam4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        PhysParameters->addWidget(PhysParam4);

        doubleSpinBox_mu = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_mu->setObjectName(QString::fromUtf8("doubleSpinBox_mu"));
        doubleSpinBox_mu->setEnabled(false);
        doubleSpinBox_mu->setMinimumSize(QSize(100, 0));
        doubleSpinBox_mu->setDecimals(4);
        doubleSpinBox_mu->setSingleStep(0.010000000000000);

        PhysParameters->addWidget(doubleSpinBox_mu);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PhysParameters->addItem(horizontalSpacer_26);


        verticalLayout->addLayout(PhysParameters);

        label_advopt = new QLabel(centralwidget);
        label_advopt->setObjectName(QString::fromUtf8("label_advopt"));
        sizePolicy2.setHeightForWidth(label_advopt->sizePolicy().hasHeightForWidth());
        label_advopt->setSizePolicy(sizePolicy2);
        label_advopt->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_advopt);

        AdvancedOpinions = new QHBoxLayout();
        AdvancedOpinions->setObjectName(QString::fromUtf8("AdvancedOpinions"));
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AdvancedOpinions->addItem(horizontalSpacer_24);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        AdvancedOpinions->addWidget(label_20);

        doubleSpinBox_modelScale = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_modelScale->setObjectName(QString::fromUtf8("doubleSpinBox_modelScale"));
        doubleSpinBox_modelScale->setMinimumSize(QSize(100, 0));
        doubleSpinBox_modelScale->setDecimals(2);
        doubleSpinBox_modelScale->setMinimum(0.010000000000000);
        doubleSpinBox_modelScale->setMaximum(1000.000000000000000);
        doubleSpinBox_modelScale->setValue(1.000000000000000);

        AdvancedOpinions->addWidget(doubleSpinBox_modelScale);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AdvancedOpinions->addItem(horizontalSpacer_27);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        AdvancedOpinions->addWidget(label_21);

        spinBox_FPS = new QSpinBox(centralwidget);
        spinBox_FPS->setObjectName(QString::fromUtf8("spinBox_FPS"));
        spinBox_FPS->setMinimumSize(QSize(100, 0));
        spinBox_FPS->setAccelerated(true);
        spinBox_FPS->setMinimum(1);
        spinBox_FPS->setMaximum(240);
        spinBox_FPS->setValue(60);

        AdvancedOpinions->addWidget(spinBox_FPS);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AdvancedOpinions->addItem(horizontalSpacer_28);

        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        AdvancedOpinions->addWidget(label_22);

        spinBox_IntegPrec = new QSpinBox(centralwidget);
        spinBox_IntegPrec->setObjectName(QString::fromUtf8("spinBox_IntegPrec"));
        spinBox_IntegPrec->setMinimumSize(QSize(100, 0));
        spinBox_IntegPrec->setMaximum(200);
        spinBox_IntegPrec->setValue(50);

        AdvancedOpinions->addWidget(spinBox_IntegPrec);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AdvancedOpinions->addItem(horizontalSpacer_29);


        verticalLayout->addLayout(AdvancedOpinions);

        FileWriteLine = new QHBoxLayout();
        FileWriteLine->setObjectName(QString::fromUtf8("FileWriteLine"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        FileWriteLine->addItem(horizontalSpacer);

        Filecheckbox = new QCheckBox(centralwidget);
        Filecheckbox->setObjectName(QString::fromUtf8("Filecheckbox"));

        FileWriteLine->addWidget(Filecheckbox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        FileWriteLine->addItem(horizontalSpacer_6);

        checkbox_Energyplot = new QCheckBox(centralwidget);
        checkbox_Energyplot->setObjectName(QString::fromUtf8("checkbox_Energyplot"));

        FileWriteLine->addWidget(checkbox_Energyplot);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        FileWriteLine->addItem(horizontalSpacer_8);

        checkbox_LA3 = new QCheckBox(centralwidget);
        checkbox_LA3->setObjectName(QString::fromUtf8("checkbox_LA3"));

        FileWriteLine->addWidget(checkbox_LA3);

        label_plotLA3 = new QLabel(centralwidget);
        label_plotLA3->setObjectName(QString::fromUtf8("label_plotLA3"));

        FileWriteLine->addWidget(label_plotLA3);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        FileWriteLine->addItem(horizontalSpacer_30);

        checkbox_Laz = new QCheckBox(centralwidget);
        checkbox_Laz->setObjectName(QString::fromUtf8("checkbox_Laz"));

        FileWriteLine->addWidget(checkbox_Laz);

        label_LAz = new QLabel(centralwidget);
        label_LAz->setObjectName(QString::fromUtf8("label_LAz"));

        FileWriteLine->addWidget(label_LAz);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        FileWriteLine->addItem(horizontalSpacer_32);

        checkbox_awL = new QCheckBox(centralwidget);
        checkbox_awL->setObjectName(QString::fromUtf8("checkbox_awL"));

        FileWriteLine->addWidget(checkbox_awL);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setTextFormat(Qt::RichText);

        FileWriteLine->addWidget(label_14);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        FileWriteLine->addItem(horizontalSpacer_33);


        verticalLayout->addLayout(FileWriteLine);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pathToLog = new QLineEdit(centralwidget);
        pathToLog->setObjectName(QString::fromUtf8("pathToLog"));
        pathToLog->setEnabled(true);
        pathToLog->setMinimumSize(QSize(350, 0));
        pathToLog->setReadOnly(true);

        horizontalLayout->addWidget(pathToLog);

        LogFileBrowser = new QPushButton(centralwidget);
        LogFileBrowser->setObjectName(QString::fromUtf8("LogFileBrowser"));

        horizontalLayout->addWidget(LogFileBrowser);


        verticalLayout->addLayout(horizontalLayout);

        LaunchLine = new QHBoxLayout();
        LaunchLine->setObjectName(QString::fromUtf8("LaunchLine"));
        LaunchLine->setContentsMargins(0, 0, -1, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        LaunchLine->addItem(horizontalSpacer_7);

        pushButtonLaunch = new QPushButton(centralwidget);
        pushButtonLaunch->setObjectName(QString::fromUtf8("pushButtonLaunch"));
        pushButtonLaunch->setFlat(false);

        LaunchLine->addWidget(pushButtonLaunch);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        LaunchLine->addItem(horizontalSpacer_9);

        helpButton = new QPushButton(centralwidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        LaunchLine->addWidget(helpButton);


        verticalLayout->addLayout(LaunchLine);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Top simulator", nullptr));
        Information->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">Various tops simulator - version 1.0</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Please begin by selecting the top you would like to simulate. The appropriate parameters will activate.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Then, if you chose &quot;Simple fixed cone&quot; or &quot;Rolling tippe top&quot;, please choose an integrator from the list. For the other two tops, the only implemented integrator capable of solving the equations is the adaptive LSODA algorithm.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">You can then choose models to use for simulation. Example models are shipped with the app.</span></p>\n"
"<p style=\"-qt-paragraph-type:emp"
                        "ty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Next, set physical and initial parameters for top. Angles are in radians. See documentation for exact meaning of parameters.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Finally, you may modify the advanced options:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\242 Model scale sets a multiplie"
                        "r by which all model sizes are multiplied. It is recommended for best visibility that the product of either radius or length multiplied by model scale is between 0.1 and 1.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\242 FPS target sets a </span><span style=\" font-size:14pt; font-style:italic;\">Frames Per Second </span><span style=\" font-size:14pt;\">target. Note that it will be limited by your monitors refresh rate. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\242 Integrator precision is a parameter that only affects the &quot;Simple fixed cone&quot; and &quot;Rolling tippe top&quot; tops. If the time between two frames is \316\224t, the time step of the used integrator will be (\316\224t)/(Integrator precision). The recommended value rarely n"
                        "eeds to be modified. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\242 Finally, you may choose to write the data created to a file. You must specify an absolute file path.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">For controls to use during simulation, press the help button.</span></p></body></html>", nullptr));
        pushButton_saveconfig->setText(QCoreApplication::translate("MainWindow", "Save configuration", nullptr));
        pushButton_loadconfig->setText(QCoreApplication::translate("MainWindow", "Load configuration", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Type of top", nullptr));
        TopSelection->setItemText(0, QCoreApplication::translate("MainWindow", "Simple fixed cone", nullptr));
        TopSelection->setItemText(1, QCoreApplication::translate("MainWindow", "Rolling tippe top", nullptr));
        TopSelection->setItemText(2, QCoreApplication::translate("MainWindow", "Slipping tippe top", nullptr));
        TopSelection->setItemText(3, QCoreApplication::translate("MainWindow", "Slipping cone", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Integrator", nullptr));
        Integrator->setItemText(0, QCoreApplication::translate("MainWindow", "Euler-Cromer", nullptr));
        Integrator->setItemText(1, QCoreApplication::translate("MainWindow", "Newmark", nullptr));
        Integrator->setItemText(2, QCoreApplication::translate("MainWindow", "Runge-Kutta order 4", nullptr));

        label_IntegratorE->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Table model", nullptr));
        comboBox_tablemodel->setItemText(0, QCoreApplication::translate("MainWindow", "Basic Table", nullptr));
        comboBox_tablemodel->setItemText(1, QCoreApplication::translate("MainWindow", "Custom...", nullptr));

        pathToTableModel->setText(QString());
        pathToTableModel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Table model path", nullptr));
        TableModelBrowser->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Top model", nullptr));
        comboBox_topmodel->setItemText(0, QCoreApplication::translate("MainWindow", "Cone", nullptr));
        comboBox_topmodel->setItemText(1, QCoreApplication::translate("MainWindow", "Tippe Top", nullptr));
        comboBox_topmodel->setItemText(2, QCoreApplication::translate("MainWindow", "Custom...", nullptr));

        pathToTopModel->setText(QString());
        pathToTopModel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Top model path", nullptr));
        TopModelBrowser->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        label_initvalues->setText(QCoreApplication::translate("MainWindow", "Initial values (angles in radians)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\316\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\317\210", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\317\206", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "m    ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "m  ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\316\270'", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\317\210'", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\317\206'", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "x'", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "y'", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_physparam->setText(QCoreApplication::translate("MainWindow", "Physical parameters", nullptr));
        massLabel->setText(QCoreApplication::translate("MainWindow", "mass", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Kg", nullptr));
        physParam2->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        PhysParam3->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        PhysParam4->setText(QCoreApplication::translate("MainWindow", "\316\274", nullptr));
        label_advopt->setText(QCoreApplication::translate("MainWindow", "Advanced options", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Model scale", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "FPS target", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Integrator Precision", nullptr));
        Filecheckbox->setText(QCoreApplication::translate("MainWindow", "Write to file", nullptr));
        checkbox_Energyplot->setText(QCoreApplication::translate("MainWindow", "Plot Energy", nullptr));
        checkbox_LA3->setText(QString());
        label_plotLA3->setText(QCoreApplication::translate("MainWindow", "Plot L<sub>A3</sub>", nullptr));
        checkbox_Laz->setText(QString());
        label_LAz->setText(QCoreApplication::translate("MainWindow", "Plot L<sub>Az</sub>", nullptr));
        checkbox_awL->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Plot a \302\267 (\317\211 x L)", nullptr));
        pathToLog->setText(QString());
        pathToLog->setPlaceholderText(QCoreApplication::translate("MainWindow", "Path to data file", nullptr));
        LogFileBrowser->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        pushButtonLaunch->setText(QCoreApplication::translate("MainWindow", "Launch simulation!", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWPHXPAK_H
