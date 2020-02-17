#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

MainWindow::~MainWindow()
{

}

MySplashScreen::MySplashScreen(QWidget *parent)
    : QSplashScreen(parent)
{

}


void MySplashScreen::onMessageChanged(const QString &message)
{
    qDebug()<<"splash message:"<<message;
}

MySplashScreen::~MySplashScreen()
{

}
