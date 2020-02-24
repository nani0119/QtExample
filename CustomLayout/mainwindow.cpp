#include "mainwindow.h"

#include <QPushButton>
#include <QSpacerItem>
#include <QStyle>
#include <QResizeEvent>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{



    QPushButton *pPushButton1 = new QPushButton();
    pPushButton1->setText("button1");

    QSpacerItem *pSpacerItem = new QSpacerItem(70,30);

    QPushButton *pPushButton2 = new QPushButton();
    pPushButton2->setText("button2");

    QPushButton *pPushButton3 = new QPushButton();
    pPushButton3->setText("button3");

    QPushButton *pPushButton4 = new QPushButton();
    pPushButton4->setText("button4");

    QPushButton *pPushButton5 = new QPushButton();
    pPushButton5->setText("button5");

    QPushButton *pPushButton6 = new QPushButton();
    pPushButton6->setText("button6");

    QPushButton *pPushButton7 = new QPushButton();
    pPushButton7->setText("button7");

    QPushButton *pPushButton8 = new QPushButton();
    pPushButton8->setText("button8");

    QPushButton *pPushButton9 = new QPushButton();
    pPushButton9->setText("button9");

    CustomLayout *layout = new CustomLayout();
    layout->setObjectName("CustomLayout");
    layout->addWidget(pPushButton1);
    layout->addItem(pSpacerItem);
    layout->addWidget(pPushButton3);
    layout->addWidget(pPushButton4);
    layout->addWidget(pPushButton5);
    layout->addWidget(pPushButton6);
    layout->addWidget(pPushButton7);
    layout->addWidget(pPushButton8);
    layout->addWidget(pPushButton9);
    layout->setSpacing(20);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<<__func__<<": size " << event->size();
    QWidget *widget = centralWidget();
    QLayout* customLayout = widget->layout();
    int height = 0;
    if(customLayout!=nullptr)
    {
        qDebug()<<__func__<<": layout " << customLayout->objectName();
        int count = customLayout->count();
        for(int i = 0; i < count; i++)
        {
            QLayoutItem* item = customLayout->itemAt(i);
            height +=item->sizeHint().height();
        }
    }
    qDebug()<<__func__<<": height " << height;
    resize(event->size().width(), height);
}


CustomLayout::CustomLayout(QWidget *parent):
    QLayout(parent)
{

}

CustomLayout::~CustomLayout()
{
    foreach (QLayoutItem* item, list) {
        delete  item;
    }
}

QSize CustomLayout::sizeHint() const
{
    int w = 0;
    int h = 0;
    foreach (QLayoutItem* item, list) {
        w += item->sizeHint().width();
        w += spacing();
        h = qMax(item->sizeHint().height()+spacing(),h);
    }

    QSize size(w,h*3);
    qDebug()<<__func__<<": w x h " << size;
    return size;
}

void CustomLayout::setGeometry(const QRect &rect)
{
    qDebug()<<__func__<<": rect " << rect;
    QLayout::setGeometry(rect);
    QWidget* parent = parentWidget();

    int x = rect.x();
    int y = rect.y();
    int nextX = x;
    int nextY = y;

    foreach (QLayoutItem* item, list) {
        item->setGeometry(QRect(QPoint(nextX,nextY), item->sizeHint()));
        nextX += item->sizeHint().width();
        if(spacing()> 0)
        {
            nextX += spacing();
        }

        if(nextX > parent->width())
        {
            nextX = x;
            nextY += item->sizeHint().height()+spacing();
        }
    }
}

QRect CustomLayout::geometry() const
{
    int w = 0;
    int h = 0;
    foreach (QLayoutItem* item, list) {
        w += item->sizeHint().width();
        if(spacing()> 0)
        {
            w += spacing();
        }
        h = qMax(item->sizeHint().height(),h);
    }
    QRect rect(QPoint(0,0),QSize(w,h));
    qDebug()<<__func__<<": rect " << rect;
    return rect;
}

void CustomLayout::addItem(QLayoutItem *item)
{
    qDebug()<<__func__;
    list.append(item);
}

QLayoutItem *CustomLayout::itemAt(int index) const
{
    qDebug()<<__func__<<":index "<<index;
    if(index < list.size())
    {
        return list.at(index);
    }
    else
    {
        return nullptr;
    }
}

QLayoutItem *CustomLayout::takeAt(int index)
{
    qDebug()<<__func__<<":index "<<index;
    if(index < list.size())
    {
        return list.takeAt(index);
    }
    else
    {
        return nullptr;
    }
}

int CustomLayout::count() const
{
    int count = list.size();
    qDebug()<<__func__<<": count "<< count;
    return  count;
}
