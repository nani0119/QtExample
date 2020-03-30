#include "mywidget.h"
#include <QDebug>
#include <QLabel>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent), val(0)
{

}

int MyWidget::value()
{
    qDebug()<<__func__<<" value: "<< val;
    return val;
}

void MyWidget::setValue(int value)
{
    qDebug()<<__func__<<" set value: "<< value;
    val = value;
}

void MyWidget::updateValue()
{
    QLabel* label = findChild<QLabel*>("label");
    label->setNum(val);
}
