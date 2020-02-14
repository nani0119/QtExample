#include "mainwindow.h"
#include <QProgressBar>
#include <QSlider>
#include <QProgressDialog>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pProgressBarBusy(new QProgressBar), pProgressBar(new QProgressBar),
      pInvertedProgressBar(new QProgressBar), pVProgressBar(new QProgressBar), pProgressDialog(new QProgressDialog(this)),
      pSlider(new QSlider)
{

    int min = 0;
    int max = 100;
    int singleStep = 1;

    QGridLayout *layout = new QGridLayout;

    pProgressBarBusy->setRange(0,0);
    layout->addWidget(pProgressBarBusy, 0, 0);

    pProgressBar->setRange(min, max);
    pProgressBar->setOrientation(Qt::Horizontal);
    pProgressBar->setTextVisible(true);
    //百分比
    pProgressBar->setFormat("当前进度：%p%");
    pProgressBar->setValue(0);
    layout->addWidget(pProgressBar, 1, 0);



    pInvertedProgressBar->setRange(min, max);
    pInvertedProgressBar->setOrientation(Qt::Horizontal);
    pInvertedProgressBar->setTextVisible(true);
    //当前步数/总步数
    pInvertedProgressBar->setFormat("当前进度：%v/%m");
    pInvertedProgressBar->setInvertedAppearance(true);
    pInvertedProgressBar->setValue(0);
    layout->addWidget(pInvertedProgressBar, 2, 0);


    pVProgressBar->setRange(min, max);
    pVProgressBar->setOrientation(Qt::Vertical);
    QString str = QString("当前进度: ").split("", QString::SkipEmptyParts).join("\n");
    pVProgressBar->setFormat(str+"\n%v\n/\n%m");
    pVProgressBar->setFixedWidth(100);
    pVProgressBar->setInvertedAppearance(false);
    pVProgressBar->setTextVisible(true);
    pVProgressBar->setValue(0);
    layout->addWidget(pVProgressBar, 0, 1, 3, 1);

    QProgressBar *bar = new QProgressBar;
    pProgressDialog->setBar(bar);
    bar->setFormat("当前进度：%p%");
    pProgressDialog->setRange(min, max);
    pProgressDialog->setAutoClose(false);
    pProgressDialog->setAutoReset(false);
    connect(pProgressDialog, SIGNAL(canceled()),this, SLOT(onProgressDialogCanceled()));
    pProgressDialog->show();

    pSlider->setRange(min, max);
    pSlider->setSingleStep(singleStep);
    pSlider->setOrientation(Qt::Horizontal);
    layout->addWidget(pSlider);
    connect(pSlider, SIGNAL(valueChanged(int)), pProgressBar, SLOT(setValue(int)));
    connect(pSlider, SIGNAL(valueChanged(int)), pInvertedProgressBar, SLOT(setValue(int)));
    connect(pSlider, SIGNAL(valueChanged(int)), pVProgressBar, SLOT(setValue(int)));
    connect(pSlider, SIGNAL(valueChanged(int)), pProgressDialog, SLOT(setValue(int)));



    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onProgressDialogCanceled()
{
    disconnect(pSlider, SIGNAL(valueChanged(int)), pProgressDialog, SLOT(setValue(int)));
}

