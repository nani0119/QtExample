#include "mainwindow.h"
#include "bar.h"

#include <QScrollArea>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Bar *bar = new Bar;
    QScrollArea *pScrollArea = new QScrollArea;
    pScrollArea->setWidget(bar);
    //pScrollArea->setBackgroundRole(QPalette::Shadow);
    //滚动区域部件将自动调整
    pScrollArea->setWidgetResizable(true);
    pScrollArea->setAlignment(Qt::AlignCenter);

    setCentralWidget(pScrollArea);
    setWindowTitle("3D bar data dispaly");
}

MainWindow::~MainWindow()
{
}

