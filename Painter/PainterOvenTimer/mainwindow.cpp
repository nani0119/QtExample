#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),myWidget(new MyWidget)
{
    setGeometry(0,0,600,480);
    setCentralWidget(myWidget);
}

MainWindow::~MainWindow()
{
}

