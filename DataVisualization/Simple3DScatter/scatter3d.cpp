#include "scatter3d.h"
#include "ui_scatter3d.h"
#include <QVBoxLayout>
#include <QtDataVisualization>
using namespace QtDataVisualization;

Scatter3D::Scatter3D(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Scatter3D)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout;

    Q3DScatter *scatter = new Q3DScatter;
    QScatter3DSeries* scatterSeries = new QScatter3DSeries;

    QScatterDataItem *item = new QScatterDataItem;
    item->setPosition(QVector3D(1,1,1));
    scatterSeries->dataProxy()->addItem(*item);

    QScatterDataArray data;
    data << QVector3D(0.5f, 0.5f, 0.5f) << QVector3D(-0.3f, -0.5f, -0.4f) << QVector3D(0.0f, -0.3f, 0.2f);
    scatterSeries->dataProxy()->addItems(data);

    scatter->addSeries(scatterSeries);



    QWidget* scatterWidget = QWidget::createWindowContainer(scatter);
    layout->addWidget(scatterWidget);
    ui->widget->setLayout(layout);

}

Scatter3D::~Scatter3D()
{
    delete ui;
}

