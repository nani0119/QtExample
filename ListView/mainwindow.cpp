#include "mainwindow.h"
#include <QListView>
#include <QStringListModel>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pListView(new QListView), pStringListModel(new QStringListModel), pLabel(new QLabel),
      pStringList(new QStringList)
{
    QGridLayout *layout = new QGridLayout;

    pLabel = new QLabel;
    layout->addWidget(pLabel,0,0,1,2);

    //pStringList->append("");
    pStringListModel->setStringList(*pStringList);

    pListView->setModel(pStringListModel);
    pListView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

    layout->addWidget(pListView,1,0,1,2);

    QPushButton *insertButton = new QPushButton("insert");
    QPushButton *delButton = new QPushButton("delete");
    QPushButton *showButton = new QPushButton("show");
    layout->addWidget(insertButton,2,0);
    layout->addWidget(delButton,2,1);
    layout->addWidget(showButton,3,0,1,2);
    connect(insertButton, SIGNAL(clicked()), this, SLOT(onInsertButtonClicked()));
    connect(delButton, SIGNAL(clicked()), this, SLOT(onDelClicked()));
    connect(showButton, SIGNAL(clicked()), this, SLOT(onShowClicked()));

    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete  pStringList;
}

void MainWindow::onInsertButtonClicked()
{
    int row = pListView->currentIndex().row();
    if(row < 0)
    {
        row = 0;
    }
    qDebug()<<__func__<<":"<<row;
    pStringListModel->insertRows(row, 1);

    QModelIndex index = pStringListModel->index(row);
    pListView->setCurrentIndex(index);
    pListView->edit(index);
}

void MainWindow::onDelClicked()
{
    int row = pListView->currentIndex().row();
    if(row < 0)
    {
        return;
    }
    pStringListModel->removeRows(pListView->currentIndex().row(),1);
}

void MainWindow::onShowClicked()
{
    QString str = "";
    foreach (QString item, pStringListModel->stringList()) {
        qDebug()<<__func__<<":"<<item;
        str += QString("%1").arg(item);
        str += "\n";
    }
    pLabel->setText(str);

}


