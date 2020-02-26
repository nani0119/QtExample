#include "mainwindow.h"
#include <QErrorMessage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QErrorMessage *errorMessage = new QErrorMessage;
    errorMessage->showMessage("error:type 1","error type");
    errorMessage->showMessage("error:type 2","error type");
    errorMessage->showMessage("error:type 1","error type");
    errorMessage->showMessage("split");
    errorMessage->showMessage("error:xxxxxx");
    errorMessage->showMessage("error:xxxxxx");
    errorMessage->showMessage("error:yyyyyy");
}

MainWindow::~MainWindow()
{
}

