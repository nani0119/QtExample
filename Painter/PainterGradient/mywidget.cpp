#include "mywidget.h"
#include <QPainter>
#include <QDebug>
#include <QGradient>
#include <QRadioButton>
#include <QGradient>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent),
    spreadType(QGradient::PadSpread),
    gradientType(QGradient::LinearGradient)
{

}

void MyWidget::gradientUpdate()
{
    QRadioButton* button = (QRadioButton*)sender();
    if(button->objectName() == "radialGradientButton")
    {
        gradientType = QGradient::RadialGradient;
    }
    else if(button->objectName() == "conicalGradientButton")
    {
        gradientType = QGradient::ConicalGradient;
    }
    else if(button->objectName() == "linearGradientButton")
    {
        gradientType = QGradient::LinearGradient;
    }

    if(button->objectName() == "repeatSpreadButton")
    {
        spreadType = QGradient::RepeatSpread;
    }
    else if(button->objectName() == "reflectSpreadButton")
    {
        spreadType = QGradient::ReflectSpread;
    }
    else if(button->objectName() == "padSpreadButton")
    {
        spreadType = QGradient::PadSpread;
    }

    update();
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);


    painter.setRenderHint(QPainter::Antialiasing, true);

    QGradient* gradient =createGradient();


    painter.setPen(QPen(QColor(0, 160, 230), 2));

    painter.setBrush(*gradient);

    painter.drawRect(QRect(40, 40, 180, 180));

    delete  gradient;
}

QGradient* MyWidget::createGradient()
{

    QGradient* ret;
    if(this->gradientType == QGradient::LinearGradient)
    {
        QLinearGradient *linearGradient = new QLinearGradient(QPointF(80, 80), QPointF(150, 150));
        linearGradient->setColorAt(0, Qt::black);
        linearGradient->setColorAt(1, Qt::white);
        ret = linearGradient;
    }

    if(this->gradientType == QGradient::RadialGradient)
    {
        QRadialGradient *radialGradient = new QRadialGradient(110, 110, 50, 130, 130);
        radialGradient->setColorAt(0, Qt::black);
        radialGradient->setColorAt(1, Qt::white);
        ret = radialGradient;
    }


    if(this->gradientType == QGradient::ConicalGradient)
    {
        QConicalGradient *conicalGradient = new QConicalGradient(110, 110, 45);
        conicalGradient->setColorAt(0, Qt::black);
        conicalGradient->setColorAt(1, Qt::white);
        ret = conicalGradient;
    }

    switch (this->spreadType) {
    case QGradient::PadSpread:
        ret->setSpread(QGradient::PadSpread);
        break;
    case QGradient::RepeatSpread:
        ret->setSpread(QGradient::RepeatSpread);
        break;
    case QGradient::ReflectSpread:
        ret->setSpread(QGradient::ReflectSpread);
        break;
    }
    return ret;
}
