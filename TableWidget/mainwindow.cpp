#include "mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pTableWidget(new QTableWidget)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *addRowButton = new QPushButton("add row");
    layout->addWidget(pLabel);

    connect(addRowButton, SIGNAL(clicked()), this, SLOT(onClicked()));
    layout->addWidget(addRowButton);


    pTableWidget->setColumnCount(2);
    pTableWidget->setHorizontalHeaderLabels(QStringList()<<"X"<<"Y");
    pTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(pTableWidget, SIGNAL(currentItemChanged(QTableWidgetItem *, QTableWidgetItem *)),
            this, SLOT(onCurrentItemChanged(QTableWidgetItem *, QTableWidgetItem *)));
    layout->addWidget(pTableWidget);


    QWidget *widget = new  QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onClicked()
{
    int row = pTableWidget->rowCount();
    pTableWidget->insertRow(row);

    QTableWidgetItem *item0 = new QTableWidgetItem;
    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    pTableWidget->setItem(row, 0,item0);

    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    pTableWidget->setItem(row, 1,item1);

    pTableWidget->setCurrentCell(row,0);
}

void MainWindow::onCurrentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
        Q_UNUSED(previous)
        if(current!=nullptr)
        {
            pLabel->setText(current->text());
        }
}

