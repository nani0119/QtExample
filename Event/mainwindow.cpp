#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent), pMyLabel(new MyLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;
    pMyLabel->setObjectName("pLabel");
    pMyLabel->installEventFilter(pMyLabel);
    pMyLabel->setText("click me");
    layout->addWidget(pMyLabel);

    this->setObjectName("myWindow");
    this->installEventFilter(this);

    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MyMainWindow::~MyMainWindow()
{
}

bool MyMainWindow::event(QEvent *event)
{
    qDebug() <<"MyMainWindow:"<<__func__;
    //return true;
    return QMainWindow::event(event);
}

void MyMainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug() <<"<=======MainWindow:"<<__func__;
}

bool MyMainWindow::eventFilter(QObject *obj, QEvent *event)
{
    qDebug() <<"MyMainWindow:"<<__func__<<":"<<obj->objectName();
    //return true;
    return QMainWindow::eventFilter(obj,event);
}

MyApplication::MyApplication(int &argc, char **argv)
    :QApplication(argc, argv)
{

}

MyApplication::~MyApplication()
{

}

bool MyApplication::notify(QObject* reciver, QEvent *e)
{
    qDebug() <<"=======>MyApplication:"<<__func__<<":"<<reciver->objectName();
    //return true;
    return QApplication::notify(reciver, e);
}

bool MyApplication::event(QEvent * e)
{
    qDebug() <<"MyApplication:"<<__func__;
    //return true;
    return QApplication::event(e);
}

bool MyApplication::eventFilter(QObject *obj, QEvent *event)
{
    qDebug() <<"MyApplication:"<<__func__<<":"<<obj->objectName();
    //return true;
    return QApplication::eventFilter(obj,event);
}

MyLabel::MyLabel(QWidget *parent)
    :QLabel(parent)
{

}

MyLabel::~MyLabel()
{

}

bool MyLabel::event(QEvent *e)
{
     qDebug() <<"MyLabel:"<<__func__;
     return QLabel::event(e);
}

bool MyLabel::eventFilter(QObject *obj, QEvent *event)
{
    qDebug() <<"MyLabel:"<<__func__<<":"<<obj->objectName();
    //return true;
    return QLabel::eventFilter(obj,event);
}

//void MyLabel::mousePressEvent(QMouseEvent *event)
//{
//    qDebug() <<"MyLabel:"<<__func__;
//}
