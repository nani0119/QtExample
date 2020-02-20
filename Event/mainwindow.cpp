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
    pMyLabel->installEventFilter(this);
    pMyLabel->setText("click me");
    layout->addWidget(pMyLabel);


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
    qDebug() <<"<=======MainWindow:"<<__func__;
}

bool MyMainWindow::eventFilter(QObject *obj, QEvent *event)
{
    qDebug() <<"MyMainWindow:"<<__func__<<":"<<obj->objectName();
    //return true;
    return QMainWindow::eventFilter(obj,event);
}


ObjectFilter::ObjectFilter(QObject *parent)
    : QObject(parent)
{

}

ObjectFilter::~ObjectFilter()
{

}

bool ObjectFilter::eventFilter(QObject *obj, QEvent *event)
{
    qDebug() <<"ObjectFilter:"<<__func__<<":"<<obj->objectName();
    //return true;
    return QObject::eventFilter(obj,event);
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

//void MyLabel::mousePressEvent(QMouseEvent *event)
//{
//    qDebug() <<"MyLabel:"<<__func__;
//}
