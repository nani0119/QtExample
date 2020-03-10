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

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::blue,1));

    //draw point
    painter.drawPoint(5,5);

    //draw line
    painter.drawLine(15,5,65,55);

    //polyline
    QPoint polylinePoint[4] = {
        QPoint(75,65),QPoint(85,5),
        QPoint(120,10),QPoint(140,65)
    };
    painter.drawPolyline(polylinePoint,4);

    //draw lines
    QLine  lines[2] = {
      QLine(160,6, 200,56),
      QLine(210,6, 230,56)
    };
    painter.drawLines(lines,2);

    const QPointF points[4] = {
                    QPointF(260.0, 80.0),
                    QPointF(280.0, 10.0),
                    QPointF(330.0, 30.0),
                    QPointF(340.0, 70.0)
    };
    painter.drawPolygon(points,4);

    //draw rect
    painter.drawRect(360,5,50,50);

    //draw round rect
    painter.drawRoundRect(430,5,50,50);

    //draw ellipse
    painter.drawEllipse(500,5,100,50);

    //draw arc
    painter.drawArc(10,100,50,50,30*16,90*16);

    //draw chord
    painter.drawChord(80,100,50,50,30*16,90*16);

    //draw pie
    painter.drawPie(150,100,50,50,30*16,90*16);

    //draw text
    painter.drawText(5,200,"Ag");

    //draw pixmap
    QPixmap pixmap(":/img/pic");
    painter.drawPixmap(5,220,65,65,pixmap);

    //draw path
    QPainterPath path;
    path.moveTo(5,300);
    path.lineTo(5,400);
    path.lineTo(105,400);
    path.lineTo(105,300);
    path.lineTo(85,300);
    path.lineTo(55,355);
    path.lineTo(25,300);
    path.lineTo(5,300);
    path.moveTo(105,350);
    path.arcTo(5,300,100,100,45*16,90*16);


    painter.drawPath(path);





}
