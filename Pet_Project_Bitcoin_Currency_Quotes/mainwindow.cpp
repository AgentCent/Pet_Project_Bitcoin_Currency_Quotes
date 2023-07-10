#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "currencyQuotation.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QInputDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    netManager = new QNetworkAccessManager(this);
    netReply = nullptr;

    serverRequestInit();
    //init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::serverRequestInit()
{
    dataBuffer.clear();
    QNetworkRequest req{QUrl(QString("https://blockchain.info/ticker"))};
    netReply = netManager->get(req);
    connect(netReply,&QNetworkReply::readyRead,this,&MainWindow::readData);
    connect(netReply,&QNetworkReply::finished,this,&MainWindow::finishReading);
}

void MainWindow::readData()
{
    dataBuffer.append(netReply->readAll());
}

void MainWindow::finishReading()
{
    if(netReply->error() != QNetworkReply::NoError){
        qDebug() << "Error : " << netReply->errorString();
        QMessageBox::warning(this,"Error",QString("Request Error").arg(netReply->errorString()));
    }else{
        objectCurrencyQuotation = QJsonDocument::fromJson(dataBuffer).object();
    }
    init();
}


void MainWindow::init()
{
    initCurrencyQuotation();
    initMainWindow();
}

void MainWindow::initCurrencyQuotation()
{
    for (auto var : objectCurrencyQuotation)
        arrayCurrencyQuotation.push_back(currencyQuotation{ var.toObject().value("symbol").toString(), var.toObject().value("15m").toDouble(), 0 });
}

void MainWindow::initMainWindow()
{
    for (std::size_t index = 0; index < arrayCurrencyQuotation.size(); ++index)
    {
        ui->currencyComboBox->addItem(arrayCurrencyQuotation[index].title);
    }
    ui->currencyLabel->setText(QString::number(arrayCurrencyQuotation[0].quotation, 'f', 3));
}


void MainWindow::createWidgets()
{
    for (std::size_t index = 0; index < currencyWidgets.size(); ++index) {
            currencyWidgets[index]->close();
        }
        currencyWidgets.clear();
        int horizontal{0};
        int vertical{0};
        int widgetIndex{0};
        for (std::size_t index = 0; index < arrayCurrencyQuotation.size(); ++index) {
            if(horizontal == 16) {
                ++vertical;
                horizontal = 0;
            }
            if(arrayCurrencyQuotation[index].status) {
                currencyWidgets.push_back(new secondwidget(this));
                currencyWidgets[widgetIndex]->setCurrency(arrayCurrencyQuotation[index].title, arrayCurrencyQuotation[index].quotation);
                currencyWidgets[widgetIndex]->setGeometry(horizontal * 100, vertical * 20, 100, 20);
                currencyWidgets[widgetIndex]->show();
                ++widgetIndex;
                ++horizontal;
            }
        }
}

void MainWindow::on_currencyComboBox_activated(int index)
{
    ui->currencyLabel->setText(QString::number(arrayCurrencyQuotation[index].quotation, 'f', 3));
    if(arrayCurrencyQuotation[index].status == 1) {
        bool oldState = ui->windowActiveCheckBox->blockSignals(true);
        ui->windowActiveCheckBox->setChecked(true);
        ui->windowActiveCheckBox->blockSignals(oldState);
    }
    else
    {
        bool oldState = ui->windowActiveCheckBox->blockSignals(false); //Исправить чтобы не запускало event CheckBox'а
        ui->windowActiveCheckBox->setChecked(false);
        ui->windowActiveCheckBox->blockSignals(oldState);
    }
}


void MainWindow::on_windowActiveCheckBox_stateChanged(int arg1)
{
    if(arg1 == 2)
        arrayCurrencyQuotation[ui->currencyComboBox->currentIndex()].status = true;
    else
        arrayCurrencyQuotation[ui->currencyComboBox->currentIndex()].status = false;

    createWidgets();
}
