#include "mywidget.h"
#include <QComboBox>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent),compositionMode(QPainter::CompositionMode_Source)
{

}

void MyWidget::onModeChanged(int index)
{
    QComboBox *comboBox = (QComboBox *)sender();
    QPainter::CompositionMode mode = (QPainter::CompositionMode)comboBox->itemData(index).toInt();
    setCompositionMode(mode);
    update();
}

void MyWidget::setCompositionMode(QPainter::CompositionMode mode)
{
    compositionMode = mode;
}

QPainter::CompositionMode MyWidget::getCompositionMode()
{
    return compositionMode;
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    QImage destinationImage(":/img/destination");
    painter.drawImage(0, 0, destinationImage);
    QPainter::CompositionMode mode = getCompositionMode();
    //mode = QPainter::CompositionMode_Source;
    qDebug()<<__func__<<" mode: "<<mode;
    painter.setCompositionMode(mode);
    QImage sourceImage(":/img/source");
    painter.drawImage(0, 0, sourceImage);
    painter.end();

}
