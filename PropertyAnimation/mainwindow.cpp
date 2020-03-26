#include "mainwindow.h"
#include <QPropertyAnimation>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*  声明动画类，并将控制对象 this (this一定是继承自QObject的窗口部件)  以及属性名 "geometry" 传入构造函数  */
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    /*  设置动画持续时长为 3 秒钟  */
    animation->setDuration(3000);
    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
    animation->setStartValue(QRect(0, 0, 3, 4));
    /*  设置动画的结束状态 结束点 (100,200)  结束大小 (300,400)  */
    animation->setEndValue(QRect(100, 200, width(), height()));

    animation->setKeyValueAt(0.2,QRect(30, 20, width()*2/3, height()*2/3));
    /*  设置动画效果  */
    animation->setEasingCurve(QEasingCurve::OutInExpo);
    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理(效果就好像智能指针里的自动delete animation) */
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    connect(animation, SIGNAL(finished()), this ,SLOT(onFinished()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::onFinished()
{
    qDebug()<<__func__<<":"<<"finished";
}

