#include "mainwindow.h"
#include <QSplitter>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),hSplitter(new QSplitter(Qt::Horizontal)), vSplitter(new QSplitter(Qt::Vertical))
{

    QLabel *labelH1 = new QLabel("labelH1");
    QLabel *labelV1 = new QLabel("labelV1");
    QLabel *labelV2 = new QLabel("labelV2");

    vSplitter->setObjectName("vSplitter");
    vSplitter->setHandleWidth(5);
    vSplitter->setStyleSheet("QSplitter#vSplitter::handle{background-color: red}");
    vSplitter->addWidget(labelV1);
    vSplitter->addWidget(labelV2);

    hSplitter->setObjectName("hSplitter");
    hSplitter->setHandleWidth(1);
    hSplitter->setStyleSheet("QSplitter#hSplitter::handle{background-color: blue}");
    hSplitter->addWidget(labelH1);
    hSplitter->addWidget(vSplitter);
    hSplitter->setFrameShape(QFrame::Box);
    hSplitter->setFrameShadow(QFrame::Raised);
    hSplitter->setOpaqueResize(true);

    connect(hSplitter, SIGNAL(splitterMoved(int, int)), this, SLOT(onHSplitterMoved(int, int)));
    connect(vSplitter, SIGNAL(splitterMoved(int, int)), this, SLOT(onVSplitterMoved(int, int)));

    setCentralWidget(hSplitter);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onHSplitterMoved(int pos, int index)
{
    qDebug()<<"hsplitter handle:" << index<< " pos： " << pos;

}

void MainWindow::onVSplitterMoved(int pos, int index)
{
    qDebug()<<"vsplitter handle:" << index<< " pos： " << pos;
    QSplitterHandle *VSplitterHandle = vSplitter->handle(index);
    if(VSplitterHandle->isVisible())
    {
        VSplitterHandle->setVisible(false);
    }
    else
    {
        VSplitterHandle->setVisible(true);
    }
}


