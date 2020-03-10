#include "mywidget.h"
#include <QPainter>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int side = qMin(width(), height());
    qDebug()<<"side:"<<side;

    painter.setViewport((width() - side) / 2, (height() - side) / 2, side, side);

    painter.setWindow(-50, -50, 100, 100);


    QPoint triangle[3] = {
        QPoint( -2, -49 ),
        QPoint( +2, -49 ),
        QPoint( 0, -47 ),
    };

    QPen thickPen(palette().foreground(), 0.5);
    QPen thinPen(palette().foreground(), 0.2);
    QColor niceBlue(150, 150, 200);

    //draw the tiny triangle
    painter.setPen(thinPen);
    painter.setBrush(palette().foreground());
    painter.drawPolygon(triangle,3);

    //draw the outer circle and fill it using a conical gradient
    QConicalGradient coneGradient(0, 0, -90.0);
    coneGradient.setColorAt(0.0, Qt::darkGray);
    coneGradient.setColorAt(0.2, niceBlue);
    coneGradient.setColorAt(0.5, Qt::white);
    coneGradient.setColorAt(1.0, Qt::darkGray);

    painter.setBrush(coneGradient);
    painter.drawEllipse(-46, -46, 92, 92);

    //fill the inner circle using a radial gradient
    QRadialGradient haloGradient(0, 0, 20, 0, 0);
    haloGradient.setColorAt(0.0, Qt::lightGray);
    haloGradient.setColorAt(0.8, Qt::darkGray);
    haloGradient.setColorAt(0.9, Qt::white);
    haloGradient.setColorAt(1.0, Qt::black);
    painter.setPen(Qt::NoPen);
    painter.setBrush(haloGradient);
    painter.drawEllipse(-20, -20, 40, 40);


    QLinearGradient knobGradient(-7, -25, 7, -25);
    knobGradient.setColorAt(0.0, Qt::black);
    knobGradient.setColorAt(0.2, niceBlue);
    knobGradient.setColorAt(0.3, Qt::lightGray);
    knobGradient.setColorAt(0.8, Qt::white);
    knobGradient.setColorAt(1.0, Qt::black);

    painter.rotate(0);
    painter.setBrush(knobGradient);
    painter.setPen(thinPen);
    painter.drawRoundRect(-7, -25, 14, 50, 99, 49);

    for (int i = 0; i < 60; ++i) {
         if (i % 5 == 0) {
             painter.setPen(thickPen);
             painter.drawLine(0, -41, 0, -44);
             painter.drawText(-15, -41, 30, 30,
                                  Qt::AlignHCenter | Qt::AlignTop,
                                  QString::number(i));
         } else {
             painter.setPen(thinPen);
             painter.drawLine(0, -42, 0, -44);
         }
         painter.rotate(-6);
     }
}
