/********************************************************************************
** Form generated from reading UI file 'mainwindowL17262.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWL17262_H
#define MAINWINDOWL17262_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QSpacerItem>
#include <QTableWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *Description;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_t;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_o;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_u;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QComboBox *Integrator;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonG;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonT;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *pathToFile;
    QMenuBar *menubar;
    QMenu *menutest;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(742, 462);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Description = new QTextBrowser(centralwidget);
        Description->setObjectName(QString::fromUtf8("Description"));

        verticalLayout->addWidget(Description);


        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Maximum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        doubleSpinBox_t = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_t->setObjectName(QString::fromUtf8("doubleSpinBox_t"));
        doubleSpinBox_t->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(doubleSpinBox_t);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        doubleSpinBox_o = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_o->setObjectName(QString::fromUtf8("doubleSpinBox_o"));
        doubleSpinBox_o->setMinimumSize(QSize(100, 0));
        doubleSpinBox_o->setAccelerated(true);

        horizontalLayout->addWidget(doubleSpinBox_o);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        doubleSpinBox_u = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_u->setObjectName(QString::fromUtf8("doubleSpinBox_u"));
        doubleSpinBox_u->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(doubleSpinBox_u);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        Integrator = new QComboBox(centralwidget);
        Integrator->setObjectName(QString::fromUtf8("Integrator"));
        Integrator->setMinimumSize(QSize(220, 0));

        horizontalLayout_2->addWidget(Integrator);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, -1, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pushButtonG = new QPushButton(centralwidget);
        pushButtonG->setObjectName(QString::fromUtf8("pushButtonG"));

        horizontalLayout_3->addWidget(pushButtonG);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        pushButtonT = new QPushButton(centralwidget);
        pushButtonT->setObjectName(QString::fromUtf8("pushButtonT"));

        horizontalLayout_3->addWidget(pushButtonT);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_3);

        pathToFile = new QLineEdit(centralwidget);
        pathToFile->setObjectName(QString::fromUtf8("pathToFile"));
        pathToFile->setMinimumSize(QSize(350, 0));

        verticalLayout->addWidget(pathToFile);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 742, 22));
        menutest = new QMenu(menubar);
        menutest->setObjectName(QString::fromUtf8("menutest"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menutest->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulateur de Toupie", 0, 0));
        Description->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Simulateur de toupie version 1.0. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Veuillez entrer:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\242 une valeur initiale pour l'angle polaire \316\270, en degr\303\251s (0 \303\251tant une toupie droite)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342"
                        "\200\242 une valeur initiale pour la vitess angulaire \317\211 de la toupie (rad/s)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\242 une valeur initiale pour le coefficient de frottement \316\274</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Choisissez ensuite un int\303\251grateur en cochant une case.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ensuite, lancez une simulation avec ces coefficients en appuyant sur un des buttons ci-dessous"
                        ":</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\242 La simulation graphique ouvre une fen\303\252tre externe avec une repr\303\251sentation en temps r\303\251el, 3D, de la toupie. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\242 La simulation sur fichier \303\251crit les valeurs dans un fichier.</p></body></html>", 0, 0));
        label->setText(QApplication::translate("MainWindow", "\316\270", 0, 0));
        label_2->setText(QApplication::translate("MainWindow", "\317\211", 0, 0));
        label_3->setText(QApplication::translate("MainWindow", "\316\274", 0, 0));
        label_4->setText(QApplication::translate("MainWindow", "Int\303\251grateur:", 0, 0));
        Integrator->clear();
        Integrator->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Euler-Cromer", 0, 0)
         << QApplication::translate("MainWindow", "Newmark", 0, 0)
         << QApplication::translate("MainWindow", "Runge-Kutta d'ordre 4", 0, 0)
        );
        pushButtonG->setText(QApplication::translate("MainWindow", "Lancer la simulation graphique!", 0, 0));
        pushButtonT->setText(QApplication::translate("MainWindow", "Lancer la simulation sur fichier", 0, 0));
        pathToFile->setText(QString());
        pathToFile->setPlaceholderText(QApplication::translate("MainWindow", " chemin d'acc\303\250s au fichier, absolu ou relatif", 0, 0));
        menutest->setTitle(QApplication::translate("MainWindow", "test", 0, 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWL17262_H
