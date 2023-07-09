#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arrayJsonNames.h"

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
    , arrayJsonNames(0)
{
    ui->setupUi(this);

    netManager = new QNetworkAccessManager(this);
    netReply = nullptr;

    init();
}

void MainWindow::init()
{
    dataBuffer.clear();
    QNetworkRequest req{QUrl(QString("https://blockchain.info/ticker"))};
    netReply = netManager->get(req);
    connect(netReply,&QNetworkReply::readyRead,this,&MainWindow::readData);
    connect(netReply,&QNetworkReply::finished,this,&MainWindow::finishReading);
}

void MainWindow::initComboBox()
{

    QStringList list;
    for (std::size_t index = 0; index < arrayJsonNames.size(); ++index)
    {
        list.append(arrayJsonNames[index].name);
    }
    auto currency = currencyQuotation.value(arrayJsonNames[0].name).toObject().value("15m").toDouble();
    ui->label->setText(QString::number(currency, 'f', 3));
    ui->comboBox->addItems(list);
}

void MainWindow::printWiget()
{
    for (std::size_t var = 0; var < cyrrencyWidgets.size(); ++var) {
        cyrrencyWidgets[var]->close();
    }
    cyrrencyWidgets.clear();
    int horizontal{0};
    int vertical{0};
    int widgetIndex{0};
    for (std::size_t index = 0; index < arrayJsonNames.size(); ++index) {
        if(horizontal == 16) {
            ++vertical;
            horizontal = 0;
        }
        if(arrayJsonNames[index].status) {
            cyrrencyWidgets.push_back(new secondwidget(this));
            cyrrencyWidgets[widgetIndex]->setCurrency(arrayJsonNames[index].name, currencyQuotation.value(arrayJsonNames[index].name).toObject().value("15m").toDouble());
            cyrrencyWidgets[widgetIndex]->setGeometry(horizontal * 100, vertical * 20, 100, 20);
            cyrrencyWidgets[widgetIndex]->show();
            ++widgetIndex;
            ++horizontal;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData()
{
    dataBuffer.append(netReply->readAll());
}

void MainWindow::finishReading()
{
    if(netReply->error() != QNetworkReply::NoError){
        qDebug() << "Error : " << netReply->errorString();
        QMessageBox::warning(this,"Error",QString("Request[Error]").arg(netReply->errorString()));
    }else{
        currencyQuotation = QJsonDocument::fromJson(dataBuffer).object();
        for (auto var : currencyQuotation) {
            JsonNamesStatus nameStatus{ var.toObject().value("symbol").toString(), 0 };
            arrayJsonNames.push_back(nameStatus);
        }
        initComboBox();
    }
}



void MainWindow::on_comboBox_activated(int index)
{
    auto currency = currencyQuotation.value(arrayJsonNames[index].name).toObject().value("15m").toDouble();
    ui->label->setText(QString::number(currency, 'f', 3));
    if(arrayJsonNames[index].status == 1) {
        ui->checkBox->setChecked(true);
    }
    else
        ui->checkBox->setChecked(false);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    for(std::size_t index = 0; index < arrayJsonNames.size(); ++index)
        if(arrayJsonNames[index].name == ui->comboBox->currentText()) {
            if(arg1 == 2)
                arrayJsonNames[index].status = 1;
            else
                arrayJsonNames[index].status = 0;
        }

    printWiget();
}
