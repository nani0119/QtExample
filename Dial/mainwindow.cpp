#include "mainwindow.h"
#include <QLabel>
#include <QDial>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pDial(new QDial)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);

    pDial->setRange(1,100);
    pDial->setSingleStep(1);
    pDial->setPageStep(10);
    pDial->setNotchTarget(2); //刻度间隙
    pDial->setWrapping(false);
    pDial->setNotchesVisible(true);
    layout->addWidget(pDial);

    pLabel->setNum(pDial->value());

    connect(pDial, SIGNAL(valueChanged(int)), this, SLOT(onDialValueChanged(int)));
    connect(pDial, SIGNAL(sliderPressed()), this, SLOT(onDialSliderPressed()));
    connect(pDial, SIGNAL(sliderMoved(int)), this, SLOT(onDialsliderMoved(int)));



    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onDialValueChanged(int val)
{
    pLabel->setNum(val);
}

void MainWindow::onDialsliderMoved(int val)
{
    qDebug()<<__func__<<":"<<val;

}

void MainWindow::onDialSliderPressed()
{
    qDebug()<<__func__;
}
