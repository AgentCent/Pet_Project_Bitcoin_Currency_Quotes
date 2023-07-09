#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwidget.h"
#include "arrayJsonNames.h"

#include <QMainWindow>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QPointF>
#include <QJsonObject>
#include <QString>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void init();
    void initComboBox();

    void printWiget();

    ~MainWindow();

private slots:
    void readData();
    void finishReading();

    void on_comboBox_activated(int index);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *netManager;
    QNetworkReply *netReply;
    QByteArray dataBuffer;
    QJsonObject currencyQuotation;

    std::vector<JsonNamesStatus> arrayJsonNames;

    std::vector<secondwidget*> cyrrencyWidgets;
};
#endif // MAINWINDOW_H
