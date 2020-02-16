#include "mainwindow.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPixmap>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //ScrollArea内有个widget，我们叫做"内容层"，内容层"相当于一块很大的幕布，按钮、label等控件都被绘制在了幕布上，
    //而QScrollArea相当于一个小窗口，透过这个小窗口我们看一看到幕布上的一小部分内容，拖动滚动条相当于在窗口后面移动幕布，
    //这样我们就能透过窗口看到幕布上不同位置的内容


    QScrollArea *pScrollArea = new QScrollArea;

    //内部的幕布容器
    QWidget *pScrollAreaWidget = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setObjectName("VBoxLayout");

    QLabel *pLabel = new QLabel;
    pLabel->setObjectName("pLabel");
    QPixmap pixmap(":/img/earth");
    pLabel->setPixmap(pixmap);
    pLabel->setStyleSheet("background: white;");
    layout->addWidget(pLabel);

    //向内容幕布容器中添加布局
    pScrollAreaWidget->setLayout(layout);
    pScrollAreaWidget->setObjectName("ScrollAreaWidget");
    //pScrollAreaWidget->setFixedSize(200,200);

    //向ScrollArea中添加组件
    pScrollArea->setWidget(pScrollAreaWidget);
    pScrollArea->setBackgroundRole(QPalette::Shadow);
    //滚动区域部件将自动调整
    pScrollArea->setWidgetResizable(true);
    pScrollArea->setAlignment(Qt::AlignCenter);
    //ScrollArea内的widget大于ScrollArea的大小就会显示滑动条
    //pScrollArea->setFixedSize(260,260);


    setCentralWidget(pScrollArea);

    // get something
    QWidget *widget = pScrollArea->widget();
    qDebug()<<"scroll area widget objectname:" << widget->objectName();
    QLayout *ly = widget->layout();
    qDebug()<<"layout objectname:" << ly->objectName();

}

MainWindow::~MainWindow()
{
}

