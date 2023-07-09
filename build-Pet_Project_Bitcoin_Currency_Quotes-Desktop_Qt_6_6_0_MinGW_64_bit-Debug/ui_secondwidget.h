/********************************************************************************
** Form generated from reading UI file 'secondwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWIDGET_H
#define UI_SECONDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondwidget
{
public:
    QLabel *label_quotatuion;
    QLabel *label_cyrrency;

    void setupUi(QWidget *secondwidget)
    {
        if (secondwidget->objectName().isEmpty())
            secondwidget->setObjectName("secondwidget");
        secondwidget->resize(100, 20);
        label_quotatuion = new QLabel(secondwidget);
        label_quotatuion->setObjectName("label_quotatuion");
        label_quotatuion->setGeometry(QRect(30, 0, 70, 20));
        label_cyrrency = new QLabel(secondwidget);
        label_cyrrency->setObjectName("label_cyrrency");
        label_cyrrency->setGeometry(QRect(0, 0, 30, 20));

        retranslateUi(secondwidget);

        QMetaObject::connectSlotsByName(secondwidget);
    } // setupUi

    void retranslateUi(QWidget *secondwidget)
    {
        secondwidget->setWindowTitle(QCoreApplication::translate("secondwidget", "Form", nullptr));
        label_quotatuion->setText(QCoreApplication::translate("secondwidget", "quotation ", nullptr));
        label_cyrrency->setText(QCoreApplication::translate("secondwidget", "currency", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondwidget: public Ui_secondwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWIDGET_H
