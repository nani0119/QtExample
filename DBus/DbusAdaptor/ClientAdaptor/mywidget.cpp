#include "mywidget.h"

#include <QLabel>
#include <QLineEdit>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    serviceWidget = new com::example::MyWidget("com.example.myWidget",
                                               "/mywidget",
                                               QDBusConnection::sessionBus(), this);
}

void MyWidget::onSetValue()
{
    QLineEdit *lineEdit = findChild<QLineEdit *>("lineEdit");
    if(serviceWidget->isValid()&&lineEdit != nullptr)
    {
        serviceWidget->setValue(lineEdit->text().toInt());
        serviceWidget->updateValue();
    }
}

void MyWidget::onShowValue()
{
    QLabel *label = findChild<QLabel *>("label");
    if(serviceWidget->isValid()&&label != nullptr)
    {
        int val = serviceWidget->value();
        label->setNum(val);
    }
}
