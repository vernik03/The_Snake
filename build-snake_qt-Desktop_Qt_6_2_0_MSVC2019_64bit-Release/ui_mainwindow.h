/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Exit;
    QPushButton *Play;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 736);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(192, 378, 256, 64));
        Exit->setStyleSheet(QString::fromUtf8("background: #86E4F9;\n"
"box-shadow: 0px 5px 15px rgba(134, 228, 249, 0.75);\n"
"border-radius: 5px;\n"
"\n"
"font-family: Comfortaa;\n"
"font-style: normal;\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
"line-height: 31px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"color:white;"));
        Play = new QPushButton(centralwidget);
        Play->setObjectName(QString::fromUtf8("Play"));
        Play->setGeometry(QRect(192, 294, 256, 64));
        Play->setStyleSheet(QString::fromUtf8("background: #86E4F9;\n"
"box-shadow: 0px 5px 15px rgba(134, 228, 249, 0.75);\n"
"border-radius: 5px;\n"
"\n"
"font-family: Comfortaa;\n"
"font-style: normal;\n"
"font-weight: bold;\n"
"font-size: 25px;\n"
"line-height: 31px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"color:white;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Snake", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
