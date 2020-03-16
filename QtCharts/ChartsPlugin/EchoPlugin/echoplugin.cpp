#include "echoplugin.h"
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

EchoPlugin::EchoPlugin(QWidget *parent) : QWidget(parent),
    echoAnswer(new QLabel)
{
    QGridLayout *layout = new QGridLayout;
    QLabel *label = new QLabel("answer:");
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(label,echoAnswer);
    layout->addLayout(formLayout,0,0);
    setLayout(layout);
}

QString EchoPlugin::echo(const QString &message)
{
    echoAnswer->setText(message);
    return message;
}

QString EchoPlugin::getPluginId()
{
   const QMetaObject *obj = metaObject();
   return obj->className();
}

QObject *EchoPlugin::getInstance()
{
    return this;
}
