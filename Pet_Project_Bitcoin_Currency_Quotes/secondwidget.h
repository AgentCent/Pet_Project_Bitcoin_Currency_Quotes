#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QWidget>

namespace Ui {
class secondwidget;
}

class secondwidget : public QWidget
{
    Q_OBJECT

public:
    explicit secondwidget(QWidget *parent = nullptr);
    void setCurrency(QString title, double quotation);
    ~secondwidget();

private:
    Ui::secondwidget *ui;
};

#endif // SECONDWIDGET_H
