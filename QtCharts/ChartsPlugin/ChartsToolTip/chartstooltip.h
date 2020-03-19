#ifndef CHARTSTOOLTIP_H
#define CHARTSTOOLTIP_H

#include <QtWidgets/QGraphicsItem>
#include <QtGui/QFont>
#include <QtCharts>

class ChartToolTip:public QGraphicsItem
{
public:
    ChartToolTip(QChart* parent);
    void setText(const QString &text);
    void setAnchor(QPointF point);
    void updateGeometry();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QString  m_text;
    QRectF   m_textRect;
    QRectF   m_rect;
    QPointF  m_anchor;
    QFont    m_font;
    QChart*  m_chart;
};
#endif
