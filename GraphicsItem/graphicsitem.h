#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
class GraphicsItem : public QGraphicsItem
{
public:
    GraphicsItem(QColor c = QColor(0,0,0), int axisLen = 100, QGraphicsItem* parent = nullptr,QPoint point = QPoint(0,0));

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPoint(QPoint point);
    void setLabel(QString text);
private:
    QColor color;
    int axisLen;
    QPoint point;
    QString label;
};


class GraphicsScene:public QGraphicsScene
{
public:
    GraphicsScene(QObject *parent = nullptr);
};

class GraphicsView: public QGraphicsView
{
public:
    GraphicsView(QWidget *parent = nullptr);
    GraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);
};
#endif // GRAPHICSITEM_H
