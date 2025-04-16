/********************************************************************************
** Form generated from reading UI file 'NetworkWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKWINDOW_H
#define UI_NETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkWindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QGroupBox *groupBox_2;
    QTextEdit *outputTextEdit;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *NetworkWindow)
    {
        if (NetworkWindow->objectName().isEmpty())
            NetworkWindow->setObjectName(QString::fromUtf8("NetworkWindow"));
        NetworkWindow->resize(608, 372);
        gridLayout = new QGridLayout(NetworkWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(NetworkWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(250, 16777215));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 4, 0, 1, 3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 5, 0, 1, 3);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 2);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 2, 2, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 3, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(NetworkWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        outputTextEdit = new QTextEdit(groupBox_2);
        outputTextEdit->setObjectName(QString::fromUtf8("outputTextEdit"));
        outputTextEdit->setGeometry(QRect(10, 20, 321, 331));

        gridLayout->addWidget(groupBox_2, 0, 1, 3, 1);

        groupBox_3 = new QGroupBox(NetworkWindow);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 40, 216, 31));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(12, 104, 81, 16));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 100, 16, 16));
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 100, 81, 22));

        gridLayout->addWidget(groupBox_3, 1, 0, 2, 1);


        retranslateUi(NetworkWindow);

        QMetaObject::connectSlotsByName(NetworkWindow);
    } // setupUi

    void retranslateUi(QWidget *NetworkWindow)
    {
        NetworkWindow->setWindowTitle(QApplication::translate("NetworkWindow", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("NetworkWindow", "UDP\351\205\215\347\275\256", nullptr));
        pushButton->setText(QApplication::translate("NetworkWindow", "\346\211\223\345\274\200\346\234\215\345\212\241\345\231\250", nullptr));
        label_4->setText(QApplication::translate("NetworkWindow", "\345\257\271\347\253\257\347\253\257\345\217\243", nullptr));
        pushButton_2->setText(QApplication::translate("NetworkWindow", "\345\205\263\351\227\255\346\234\215\345\212\241\345\231\250", nullptr));
        lineEdit_2->setText(QApplication::translate("NetworkWindow", "8080", nullptr));
        label->setText(QApplication::translate("NetworkWindow", "\346\234\254\345\234\260\345\234\260\345\235\200", nullptr));
        lineEdit->setText(QApplication::translate("NetworkWindow", "127.0.0.1", nullptr));
        label_3->setText(QApplication::translate("NetworkWindow", "\345\257\271\347\253\257\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("NetworkWindow", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        groupBox_2->setTitle(QApplication::translate("NetworkWindow", "\346\266\210\346\201\257\346\230\276\347\244\272\345\214\272", nullptr));
        groupBox_3->setTitle(QApplication::translate("NetworkWindow", "\346\223\215\344\275\234", nullptr));
        pushButton_3->setText(QApplication::translate("NetworkWindow", "\346\270\205\347\251\272\346\266\210\346\201\257\345\214\272", nullptr));
        label_5->setText(QApplication::translate("NetworkWindow", "\345\217\221\351\200\201\351\227\264\351\232\224\357\274\232", nullptr));
        label_6->setText(QApplication::translate("NetworkWindow", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkWindow: public Ui_NetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKWINDOW_H
