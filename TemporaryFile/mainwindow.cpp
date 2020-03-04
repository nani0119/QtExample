#include "mainwindow.h"
#include <QTemporaryFile>
#include <QDir>
#include <QLabel>
#include <QVBoxLayout>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);

    // 设置模板名称
    QString strFileName = QDir::tempPath() + QDir::separator() + QCoreApplication::applicationName() + "_XXXXXX." + "docx";
    QTemporaryFile temporaryFile(strFileName);
    // 超出作用域临时文件会自动删除
    temporaryFile.setAutoRemove(false);
    QString str = "";

    if(temporaryFile.open())
    {
        str +=QString("tempPath:%1\n").arg(QDir::tempPath());
        str +=QString("fileTemplate:%1\n").arg(temporaryFile.fileTemplate());
        str +=QString("file name:%1\n").arg(temporaryFile.fileName());
        // temporaryFile.remove();
    }
    else
    {
        str += "failed to write temporary file";
    }

    pLabel->setText(str);
    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

