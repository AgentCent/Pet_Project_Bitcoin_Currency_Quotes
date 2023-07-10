/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *currencyComboBox;
    QLabel *currencyLabel;
    QCheckBox *windowActiveCheckBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(300, 150);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        currencyComboBox = new QComboBox(centralwidget);
        currencyComboBox->setObjectName("currencyComboBox");
        currencyComboBox->setGeometry(QRect(0, 0, 70, 30));
        currencyLabel = new QLabel(centralwidget);
        currencyLabel->setObjectName("currencyLabel");
        currencyLabel->setGeometry(QRect(80, 0, 220, 30));
        windowActiveCheckBox = new QCheckBox(centralwidget);
        windowActiveCheckBox->setObjectName("windowActiveCheckBox");
        windowActiveCheckBox->setGeometry(QRect(0, 30, 121, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 300, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        currencyLabel->setText(QCoreApplication::translate("MainWindow", "Currency quotes", nullptr));
        windowActiveCheckBox->setText(QCoreApplication::translate("MainWindow", "Display separately", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
