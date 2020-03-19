#include "graphicsitem.h"
#include <QPainter>
#include <QDebug>

GraphicsItem::GraphicsItem(QColor c, int axisLen,QGraphicsItem *parent,QPoint point):QGraphicsItem(parent),
    color(c),axisLen(axisLen),point(point),label("")
{

}

QRectF GraphicsItem::boundingRect() const
{
    qDebug()<<__func__;
    return QRectF(-axisLen,-axisLen,2*axisLen,2*axisLen);
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug()<<__func__;
    painter->setRenderHint(QPainter::Antialiasing, false);
    painter->setPen(QPen(color));

    QPainterPath xArrow;
    xArrow.moveTo(axisLen-10,-10);
    xArrow.lineTo(axisLen,0);
    xArrow.moveTo(axisLen-10,10);
    xArrow.lineTo(axisLen,0);
    painter->drawLine(QLineF(-axisLen,0,axisLen,0));
    painter->drawPath(xArrow);

    QPainterPath yArrow;
    yArrow.moveTo(-10,axisLen-10);
    yArrow.lineTo(0,axisLen);
    yArrow.moveTo(10,axisLen-10);
    yArrow.lineTo(0,axisLen);
    painter->drawLine(QLineF(0,-axisLen,0,axisLen));
    painter->drawPath(yArrow);

    painter->drawText(2, -axisLen + 10, label);

    //painter->drawRect(QRectF(10,10,axisLen/2,axisLen/2));
    painter->drawLine(point.x()-3 ,point.y(), point.x()+3,point.y());
    painter->drawLine(point.x() ,point.y()-3, point.x(),point.y()+3);

    qDebug()<<"item pos:"<<label<<":"<<pos();
    qDebug()<<"map point to parent:"<< label<<":" << mapToParent(point);
    qDebug()<<"map point to scenc:"<< label<<":" << mapToScene(point);

    qDebug()<<"map parent(0,0) to me:"<< label<<":" << mapFromParent(QPoint(0,0));
    qDebug()<<"map scene(0,0) to me:"<< label<<":" << mapFromScene(QPoint(0,0));

}

void GraphicsItem::setPoint(QPoint p)
{
    this->point = p;
    update();
}

void GraphicsItem::setLabel(QString text)
{
    label = text;
}

GraphicsScene::GraphicsScene(QObject *parent):QGraphicsScene(parent)
{
    GraphicsItem *sceneAixs = new GraphicsItem(QColor(0,255,0),400);
    sceneAixs->setLabel("scene");
    addItem(sceneAixs);
}

GraphicsView::GraphicsView(QWidget *parent):QGraphicsView(parent)
{

}

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent):QGraphicsView(scene, parent)
{

}
