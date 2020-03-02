#include "mainwindow.h"
#include <QTreeView>
#include <QDirModel>
#include <QPushButton>
#include <QDebug>
#include <QGridLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pTreeView(new QTreeView), pDirModel(new QDirModel)
{
    QGridLayout *layout = new QGridLayout;


    pDirModel->setReadOnly(false);
    pDirModel->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    pTreeView->setModel(pDirModel);
    QHeaderView *headerView = pTreeView->header();
    headerView->setStretchLastSection(true);
    headerView->setSortIndicator(0,Qt::AscendingOrder);
    headerView->setSortIndicatorShown(true);

    QModelIndex index = pDirModel->index(QDir::currentPath());
    pTreeView->expand(index);
    pTreeView->scrollTo(index);
    pTreeView->resizeColumnToContents(0);

    layout->addWidget(pTreeView,0,0,1,3);

    QPushButton *creatDirButton = new QPushButton("create dir");
    QPushButton *removeButton = new QPushButton("remove");
    QPushButton *quitButton = new QPushButton("quit");
    layout->addWidget(creatDirButton, 1,0);
    layout->addWidget(removeButton, 1,1);
    layout->addWidget(quitButton, 1,2);

    connect(creatDirButton,SIGNAL(clicked()), this, SLOT(onCreateDir()));
    connect(removeButton,SIGNAL(clicked()), this, SLOT(onRemove()));
    connect(quitButton,SIGNAL(clicked()), this, SLOT(close()));

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onCreateDir()
{
    QModelIndex index = pTreeView->currentIndex();
    if(!index.isValid())
    {
        return;
    }

    QString dirName = QInputDialog::getText(this, "Create Directory", "Directory name");
    qDebug()<<__func__<<"dir name:"<<dirName;
     if (!dirName.isEmpty())
     {
           if(!pDirModel->mkdir(index,dirName).isValid())
           {
               QMessageBox::information(this, "Create Directory",
                                   "Failed to create the directory");
           }
     }
}

void MainWindow::onRemove()
{
    QModelIndex index = pTreeView->currentIndex();
    if (!index.isValid()){
        return;
    }

    bool ok;
    if(pDirModel->fileInfo(index).isDir())
    {
        ok = pDirModel->rmdir(index);
    }
    else
    {
        ok = pDirModel->remove(index);
    }
    if (!ok)
    {
        QMessageBox::information(this, "Remove",
                                 QString("Failed to remove %1").arg(pDirModel->fileName(index)));
    }
}

