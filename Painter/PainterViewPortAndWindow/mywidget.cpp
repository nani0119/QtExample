#include "mywidget.h"
#include <QPainter>
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent),
    mWindowX(0),mWindowY(0),mWindowWidth(500),mWindowHeight(300),
    mViewPortX(0),mViewPortY(0),mViewPortWidth(500),mViewPortHeight(300),
    mDrawRectX(0),mDrawRectY(0),mDrawRectWidth(100),mDrawRectHeight(100)
{

}

MyWidget::~MyWidget()
{

}

void MyWidget::onWindowChanged(int val)
{
    qDebug()<<__func__<<" :" <<val;
    update();
}

int MyWidget::windowX()
{
    return mWindowX;
}

void MyWidget::resetWindowX()
{
    mWindowX = 0;
}

void MyWidget::setWindowX(int val)
{
    qDebug()<<__func__<<" x:" <<val;
    mWindowX = val;
    emit windowXChanged(val);
}

int MyWidget::windowY()
{
    return mWindowY;
}

void MyWidget::resetWindowY()
{
    mWindowY = 0;
}

void MyWidget::setWindowY(int val)
{
    qDebug()<<__func__<<" y:" <<val;
    mWindowY = val;
    emit windowYChanged(val);
}

int MyWidget::windowWidth()
{
    return mWindowWidth;
}

void MyWidget::resetWindowWidth()
{
    mWindowWidth = 0;
}

void MyWidget::setWindowWidth(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mWindowWidth = val;
    emit windowWidthChanged(val);
}

int MyWidget::windowHeight()
{
    return mWindowHeight;
}

void MyWidget::resetWindowHeight()
{
    mWindowHeight = 0;
}

void MyWidget::setWindowHeight(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mWindowHeight = val;
    emit windowHeightChanged(val);
}


int MyWidget::viewPortHeight()
{
    return mViewPortHeight;
}

void MyWidget::resetViewPortHeight()
{
    mViewPortHeight = 0;
}

void MyWidget::setViewPortHeight(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mViewPortHeight = val;
    emit viewPortHeightChanged(val);
}

int MyWidget::viewPortWidth()
{
    return mViewPortWidth;
}

void MyWidget::resetViewPortWidth()
{
    mViewPortWidth = 0;
}

void MyWidget::setViewPortWidth(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mViewPortWidth = val;
    emit viewPortWidthChanged(val);
}


int MyWidget::viewPortX()
{
    return mViewPortX;
}

void MyWidget::resetViewPortX()
{
    mViewPortX = 0;
}

void MyWidget::setViewPortX(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mViewPortX = val;
    emit viewPortXChanged(val);
}

int MyWidget::viewPortY()
{
    return mViewPortY;
}

void MyWidget::resetViewPortY()
{
    mViewPortY = 0;
}

void MyWidget::setViewPortY(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mViewPortY = val;
    emit viewPortYChanged(val);
}

int MyWidget::drawRectX()
{
    return mDrawRectX;
}

void MyWidget::resetDrawRectX()
{
    mDrawRectX = 0;
}

void MyWidget::setDrawRectX(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mDrawRectX = val;
    emit drawRectXChanged(val);
}

int MyWidget::drawRectY()
{
    return mDrawRectY;
}

void MyWidget::resetDrawRectY()
{
    mDrawRectY = 0;
}

void MyWidget::setDrawRectY(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mDrawRectY = val;
    emit drawRectYChanged(val);
}

int MyWidget::drawRectWidth()
{
    return mDrawRectWidth;
}

void MyWidget::resetDrawRectWidth()
{
    mDrawRectWidth = 0;
}

void MyWidget::setDrawRectWidth(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mDrawRectWidth = val;
    emit drawRectWidthChanged(val);
}

int MyWidget::drawRectHeight()
{
    return mDrawRectHeight;
}

void MyWidget::resetDrawRectHeight()
{
    mDrawRectHeight = 0;
}

void MyWidget::setDrawRectHeight(int val)
{
    qDebug()<<__func__<<" :" <<val;
    mDrawRectHeight = val;
    emit drawRectHeightChanged(val);
}


void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    qDebug()<<__func__<<" windoxX:" <<windowX() << "  windowY:" << windowY() << "  "<<windowWidth()<<"x" <<windowHeight();
    qDebug()<<__func__<<" viewPortX:" <<viewPortX() << "  viewPortY:" << viewPortY() << "  "<<viewPortWidth()<<"x" <<viewPortHeight();
    qDebug()<<__func__<<" drawRectX:" <<drawRectX() << "  drawRectY:" << drawRectY() << "  "<<drawRectWidth()<<"x" <<drawRectHeight();

    QPainter painter(this);
    painter.setWindow(windowX(), windowY(), windowWidth(),windowHeight());
    painter.setViewport(viewPortX(), viewPortY(), viewPortWidth(),viewPortHeight());
    //qDebug()<<__func__<< painter.window()<<"   " <<painter.viewport();
    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
    painter.drawRect(drawRectX(), drawRectY(), drawRectWidth(), drawRectHeight());
    //逻辑原点标定
    painter.setPen(QPen(Qt::red, 1, Qt::DotLine));
    painter.drawPoint(0,0);
    painter.end();

}
