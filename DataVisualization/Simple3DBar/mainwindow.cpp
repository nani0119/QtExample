#include "mainwindow.h"
#include <QVBoxLayout>
#include <QtDataVisualization>
using namespace  QtDataVisualization;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Q3DBars *bars = new Q3DBars;

    bars->rowAxis()->setRange(0, 4);
    bars->columnAxis()->setRange(0, 4);

    QBar3DSeries *series = new QBar3DSeries;

    QBarDataRow *data = new QBarDataRow;
    *data << 1.0f << 3.0f << 7.5f << 5.0f << 2.2f;

    QBarDataRow *data1 = new QBarDataRow;
    *data1 << 0.5f << 1.5f << 3.75f << 2.5f << 1.1f;

    series->dataProxy()->addRow(data1);
    series->dataProxy()->addRow(data);


    bars->addSeries(series);
    bars->show();

    QWidget* container = createWindowContainer(bars);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(container,1);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

