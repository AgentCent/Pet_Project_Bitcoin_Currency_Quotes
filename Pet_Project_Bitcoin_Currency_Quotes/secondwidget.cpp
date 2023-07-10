#include "secondwidget.h"
#include "ui_secondwidget.h"

secondwidget::secondwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

secondwidget::~secondwidget()
{
    delete ui;
}


void secondwidget::setCurrency(QString title, double quotation)
{
    ui->label_cyrrency->setText(title);
    ui->label_quotatuion->setText(QString::number(quotation, 'f', 3));
}
