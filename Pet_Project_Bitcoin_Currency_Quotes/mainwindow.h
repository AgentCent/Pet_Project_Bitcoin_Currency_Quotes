#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwidget.h"
#include "currencyQuotation.h"

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

    ~MainWindow();


private slots:
    //void initT();

    void serverRequestInit();
    void readData();
    void finishReading();


    void init();
    void initCurrencyQuotation();
    void initMainWindow();


    void createWidgets();


    void on_currencyComboBox_activated(int index);

    void on_windowActiveCheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *netManager;
    QNetworkReply *netReply;
    QByteArray dataBuffer;
    QJsonObject objectCurrencyQuotation;


    std::vector<currencyQuotation> arrayCurrencyQuotation;


    std::vector<secondwidget*> currencyWidgets;



};
#endif // MAINWINDOW_H
