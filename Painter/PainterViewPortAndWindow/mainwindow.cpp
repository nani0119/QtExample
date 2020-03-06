#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->windowXSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setWindowX(int)));
    connect(ui->myWidget, SIGNAL(windowXChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->windowYSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setWindowY(int)));
    connect(ui->myWidget, SIGNAL(windowYChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->windowWidthSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setWindowWidth(int)));
    connect(ui->myWidget, SIGNAL(windowWidthChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->windowHeightSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setWindowHeight(int)));
    connect(ui->myWidget, SIGNAL(windowHeightChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));





    connect(ui->viewPortXSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setViewPortX(int)));
    connect(ui->myWidget, SIGNAL(viewPortXChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->viewPortYSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setViewPortY(int)));
    connect(ui->myWidget, SIGNAL(viewPortYChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->viewPortWidthSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setViewPortWidth(int)));
    connect(ui->myWidget, SIGNAL(viewPortWidthChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->viewPortHeightSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setViewPortHeight(int)));
    connect(ui->myWidget, SIGNAL(viewPortHeightChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));



    connect(ui->drawRectXSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setDrawRectX(int)));
    connect(ui->myWidget, SIGNAL(drawRectXChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->drawRectYSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setDrawRectY(int)));
    connect(ui->myWidget, SIGNAL(drawRectYChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->drawRectWidthSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setDrawRectWidth(int)));
    connect(ui->myWidget, SIGNAL(drawRectWidthChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));

    connect(ui->drawRectHeightSpinBox, SIGNAL(valueChanged(int)), ui->myWidget,SLOT(setDrawRectHeight(int)));
    connect(ui->myWidget, SIGNAL(drawRectHeightChanged(int)),ui->myWidget,SLOT(onWindowChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
