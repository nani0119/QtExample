#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->setValue,SIGNAL(clicked()), ui->widget, SLOT(onSetValue()));
    connect(ui->showValue,SIGNAL(clicked()), ui->widget, SLOT(onShowValue()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

