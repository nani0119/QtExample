#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget_adaptor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    connection(QDBusConnection::sessionBus())
{
    ui->setupUi(this);

    new MyWidgetAdaptor(ui->widget);
    connection = QDBusConnection::sessionBus();
    connection.registerService("com.example.myWidget");
    connection.registerObject("/mywidget", ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

