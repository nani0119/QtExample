#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}


MyMainWindow::MyMainWindow(QWidget *parent) :
    MainWindow(parent)
{

}

MyMainWindow::MyMainWindow(int v,QWidget *parent):
   MainWindow(parent),val(v)
{

}

MyMainWindow::~MyMainWindow()
{

}

int MyMainWindow::echo(int i)
{
    return i+1;
}

int MyMainWindow::getVal()
{
    return val;
}
