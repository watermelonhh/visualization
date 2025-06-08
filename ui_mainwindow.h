/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCustomPlot *xplotwidget;
    QCustomPlot *yplotwidget;
    QCustomPlot *zplotwidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCustomPlot *qcustomplot1;
    QCustomPlot *qcustomplot;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *mytextEdit;
    QMenuBar *menubar;
    QMenu *actionFile;
    QMenu *actionSerial;
    QMenu *actionNetwork;
    QMenu *depthmenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(833, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 40));
        groupBox_3->setMaximumSize(QSize(16777215, 200));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        xplotwidget = new QCustomPlot(groupBox_3);
        xplotwidget->setObjectName(QString::fromUtf8("xplotwidget"));

        gridLayout_3->addWidget(xplotwidget, 0, 0, 1, 1);

        yplotwidget = new QCustomPlot(groupBox_3);
        yplotwidget->setObjectName(QString::fromUtf8("yplotwidget"));

        gridLayout_3->addWidget(yplotwidget, 0, 1, 1, 1);

        zplotwidget = new QCustomPlot(groupBox_3);
        zplotwidget->setObjectName(QString::fromUtf8("zplotwidget"));

        gridLayout_3->addWidget(zplotwidget, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        qcustomplot1 = new QCustomPlot(groupBox_2);
        qcustomplot1->setObjectName(QString::fromUtf8("qcustomplot1"));

        gridLayout_2->addWidget(qcustomplot1, 1, 0, 1, 1);

        qcustomplot = new QCustomPlot(groupBox_2);
        qcustomplot->setObjectName(QString::fromUtf8("qcustomplot"));

        gridLayout_2->addWidget(qcustomplot, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(200, 400));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mytextEdit = new QTextEdit(groupBox);
        mytextEdit->setObjectName(QString::fromUtf8("mytextEdit"));
        mytextEdit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(mytextEdit);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 833, 23));
        actionFile = new QMenu(menubar);
        actionFile->setObjectName(QString::fromUtf8("actionFile"));
        actionSerial = new QMenu(menubar);
        actionSerial->setObjectName(QString::fromUtf8("actionSerial"));
        actionNetwork = new QMenu(menubar);
        actionNetwork->setObjectName(QString::fromUtf8("actionNetwork"));
        depthmenu = new QMenu(menubar);
        depthmenu->setObjectName(QString::fromUtf8("depthmenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(actionFile->menuAction());
        menubar->addAction(actionSerial->menuAction());
        menubar->addAction(actionNetwork->menuAction());
        menubar->addAction(depthmenu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QString());
        actionFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\257\273\345\217\226", nullptr));
        actionSerial->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        actionNetwork->setTitle(QApplication::translate("MainWindow", "\347\275\221\345\217\243\351\205\215\347\275\256", nullptr));
        depthmenu->setTitle(QApplication::translate("MainWindow", "\346\267\261\345\272\246\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
