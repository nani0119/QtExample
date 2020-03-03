#include "mainwindow.h"
#include <QTimer>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pTimer(new QTimer(this)), pProgressBar(new QProgressBar)
{
    QGridLayout *layout = new QGridLayout;

    pProgressBar->setRange(0,100);
    pProgressBar->setOrientation(Qt::Horizontal);
    pProgressBar->setFormat("%p%");
    pProgressBar->setValue(0);
    layout->addWidget(pProgressBar,0,0,1,2);
    QPushButton *start = new QPushButton("开始");
    QPushButton *stop = new QPushButton("停止");
    layout->addWidget(start, 1,0);
    layout->addWidget(stop, 1,1);

    pTimer->setInterval(500);
    connect(pProgressBar,SIGNAL(valueChanged(int)),this, SLOT(onMainWindowValueChanged(int)));
    connect(pTimer, SIGNAL(timeout()),this, SLOT(onMainWindowTimeout()));
    connect(start, SIGNAL(clicked()),this, SLOT(onMainWindowStartTimer()));
    connect(stop, SIGNAL(clicked()),this, SLOT(onMainWindowStopTimer()));


    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onMainWindowTimeout()
{
    int val = pProgressBar->value();
    pProgressBar->setValue(val+1);
}

void MainWindow::onMainWindowStartTimer()
{
    if(pProgressBar->value() == pProgressBar->maximum())
    {
        pProgressBar->setValue(0);
    }
    if(pTimer->isActive())
    {
        return;
    }
    pTimer->start();
}

void MainWindow::onMainWindowStopTimer()
{
    if(!pTimer->isActive())
    {
        return;
    }
    pTimer->stop();
}

void MainWindow::onMainWindowValueChanged(int val)
{
    if(pProgressBar->maximum() == val)
    {
        pTimer->stop();
    }
}

