#include "mainwindow.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QPushButton>
#include <QHeaderView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pFileDialog(new QFileDialog),pTreeWidget(new QTreeWidget)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);

    pTreeWidget->setColumnCount(3);
    pTreeWidget->setHeaderLabels(QStringList()<<"name"<<"size"<<"permission");
    pTreeWidget->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    pTreeWidget->header()->setSectionResizeMode(1, QHeaderView::Stretch);
    pTreeWidget->header()->setSectionResizeMode(2, QHeaderView::Stretch);

    layout->addWidget(pTreeWidget);


    QPushButton *pushbotton = new QPushButton("select dir");
    layout->addWidget(pushbotton);
    connect(pushbotton, SIGNAL(clicked()), this, SLOT(onClick()));
    connect(pFileDialog, SIGNAL(fileSelected(const QString&)), this, SLOT(onFileDialogFileSelected(const QString&)));
    connect(pTreeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)),this, SLOT(onCurrentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)));

    QFile qssFile(":/qss/main.qss");
    qssFile.open(QIODevice::ReadOnly);
    QTextStream qssText(&qssFile);
    QString qss = qssText.readAll();
    pTreeWidget->setStyleSheet(qss);
    qssFile.close();

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onClick()
{
    pFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
    pFileDialog->setFileMode(QFileDialog::DirectoryOnly);
    pFileDialog->setViewMode(QFileDialog::Detail);
    pFileDialog->exec();

}

void MainWindow::onFileDialogFileSelected(const QString &file)
{
    pLabel->setText(file);
    pTreeWidget->clear();
    travelDir(nullptr,file);
}

void MainWindow::onCurrentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    QString str = "";
    if(current != nullptr)
    {
        str += QString("current file: %1\n").arg(current->data(0,Qt::UserRole).toString());
    }
    else
    {
        str += "current file: nullptr\n";
    }
    if(previous != nullptr)
    {
        str += QString("previous file: %1\n").arg(previous->data(0,Qt::UserRole).toString());
    }
    else
    {
        str += "previous file: nullptr\n";
    }
    pLabel->setText(str);
}

void MainWindow::travelDir(QTreeWidgetItem *parent, QString path)
{
    if(path.size() == 0)
    {
        return;
    }
    QDir dir(path);
    if(!dir.exists())
    {
        return;
    }
    if(parent == nullptr)
    {
        parent = pTreeWidget->invisibleRootItem();
    }
    dir.setFilter(QDir::AllEntries);
    QFileInfoList fileList = dir.entryInfoList();
    int fileCount = fileList.count();
    for (int index = 0; index < fileCount; index++)
    {
        QFileInfo fileInfo = fileList[index];

        if(fileInfo.isHidden())
        {
            continue;
        }
        QTreeWidgetItem *item;
        if(fileInfo.isDir())
        {
            qDebug()<<">>>> "<<fileInfo.absoluteFilePath();
            item = new QTreeWidgetItem(parent);
            item->setText(0,fileInfo.fileName());
            item->setText(1, QString("%1").arg(fileInfo.size()));
            item->setText(2, QString("%1").arg(fileInfo.permissions()));
            item->setData(0,Qt::UserRole,fileInfo.absoluteFilePath());
            travelDir(item,fileInfo.absoluteFilePath());
        }
        else
        {
            qDebug()<<fileInfo.absoluteFilePath();
            item = new QTreeWidgetItem(parent);
            item->setText(0,fileInfo.fileName());
            item->setText(1, QString("%1").arg(fileInfo.size()));
            item->setText(2, QString("%1").arg(fileInfo.permissions()));
            item->setData(0,Qt::UserRole,fileInfo.absoluteFilePath());
        }
    }

}

