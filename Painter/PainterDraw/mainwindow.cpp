#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),myWidget(new MyWidget)
{
    setCentralWidget(myWidget);
}

MainWindow::~MainWindow()
{
}

