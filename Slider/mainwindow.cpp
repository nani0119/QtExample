#include "mainwindow.h"
#include <QSpinBox>
#include <QSlider>
#include <QFile>
#include <QTextStream>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pHSlider(new QSlider), pVSlider(new QSlider), pSpinBox(new QSpinBox)
{
    int min = 0;
    int max = 100;
    int singleStep = 10;

    QGridLayout *layout = new QGridLayout;

    pSpinBox->setRange(min, max);
    pSpinBox->setSingleStep(singleStep);
    layout->addWidget(pSpinBox,1,0,Qt::AlignVCenter|Qt::AlignHCenter);


    pVSlider->setRange(min,max);
    pVSlider->setSingleStep(singleStep);
    pVSlider->setTickPosition(QSlider::TicksRight);
    pVSlider->setTickInterval(singleStep*2);
    pVSlider->setOrientation(Qt::Vertical);
    layout->addWidget(pVSlider, 0, 1, 2, 1);

    pHSlider->setRange(min, max);
    pHSlider->setSingleStep(singleStep);
    pHSlider->setTickPosition(QSlider::TicksAbove);
    pHSlider->setOrientation(Qt::Horizontal);
    layout->addWidget(pHSlider,2,0,1,2);

    connect(pSpinBox, SIGNAL(valueChanged(int)),pVSlider, SLOT(setValue(int)));
    connect(pSpinBox, SIGNAL(valueChanged(int)),pHSlider, SLOT(setValue(int)));
    connect(pHSlider, SIGNAL(valueChanged(int)),pSpinBox, SLOT(setValue(int)));
    connect(pVSlider, SIGNAL(valueChanged(int)),pSpinBox, SLOT(setValue(int)));


    QFile qssFile(":/qss/main.qss");
    qssFile.open(QFile::ReadOnly);
    QTextStream qssText(&qssFile);
    QString qss = qssText.readAll();

    QWidget *widget = new QWidget(this);
    widget->setStyleSheet(qss);
    qssFile.close();
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

