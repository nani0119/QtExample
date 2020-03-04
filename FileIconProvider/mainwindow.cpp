#include "mainwindow.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileIconProvider>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QIcon>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pShowAllTypeIcon(new QListWidget),pShowFileIcon(new QListWidget)
{
    QVBoxLayout *layout = new QVBoxLayout;

    for(int i = 0; i < 7; i++)
    {
        QListWidgetItem *listItem = new QListWidgetItem(pShowAllTypeIcon);
        QFileIconProvider fileIconProvider;
        QIcon icon = fileIconProvider.icon(static_cast<QFileIconProvider::IconType>(i));
        listItem->setIcon(icon);
        listItem->setText(QString("%1").arg(i));
        pShowAllTypeIcon->addItem(listItem);
    }
    pShowAllTypeIcon->setIconSize(QSize(48, 48));
    pShowAllTypeIcon->setResizeMode(QListView::Adjust);
    pShowAllTypeIcon->setViewMode(QListView::IconMode);
    pShowAllTypeIcon->setSpacing(20);
    layout->addWidget(pShowAllTypeIcon);

    QPushButton *button = new QPushButton("显示文件图标");
    layout->addWidget(button);

    pShowFileIcon->setIconSize(QSize(48, 48));
    pShowFileIcon->setResizeMode(QListView::Adjust);
    pShowFileIcon->setViewMode(QListView::IconMode);
    layout->addWidget(pShowFileIcon);

    connect(button,SIGNAL(clicked()),this,SLOT(onButtonClicked()));

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onButtonClicked()
{

    QFileDialog diaglog;
    diaglog.setFileMode(QFileDialog::AnyFile);
    diaglog.setAcceptMode(QFileDialog::AcceptOpen);
    diaglog.setViewMode(QFileDialog::Detail);
    diaglog.setFilter(QDir::NoDotAndDotDot);
    diaglog.setOption(QFileDialog::DontUseNativeDialog);
    //diaglog.setNameFilter("*.*");

    if(diaglog.exec() == QDialog::Accepted)
    {
        QString fileName = diaglog.selectedFiles()[0];
        pShowFileIcon->clear();
        QFileInfo fileInfo(fileName);
        QFileIconProvider fileIconProvider;
        QIcon icon = fileIconProvider.icon(fileInfo);
        QListWidgetItem *listWidgetItem = new QListWidgetItem(pShowFileIcon);
        listWidgetItem->setIcon(icon);
        listWidgetItem->setText(fileIconProvider.type(fileInfo));
        pShowFileIcon->addItem(listWidgetItem);
    }
}

