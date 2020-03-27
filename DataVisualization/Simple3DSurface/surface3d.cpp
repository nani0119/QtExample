#include "surface3d.h"
#include "ui_surface3d.h"
#include <QVBoxLayout>
#include <QtDataVisualization>
using namespace QtDataVisualization;


Surface3D::Surface3D(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Surface3D)
{
    ui->setupUi(this);
    Q3DSurface *surface = new Q3DSurface;
    QWidget *surfaceWidget = QWidget::createWindowContainer(surface);

    QSurface3DSeries *series = new QSurface3DSeries;

    QSurfaceDataRow* row1 = new QSurfaceDataRow;
    *row1<< QVector3D(0.0f, 0.1f, 0.5f) << QVector3D(1.0f, 0.5f, 0.5f);

    QSurfaceDataRow* row2 = new QSurfaceDataRow;
    *row2<<QVector3D(0.0f, 1.8f, 1.0f)<< QVector3D(1.0f, 1.2f, 1.0f);

    QSurfaceDataArray *data = new QSurfaceDataArray;
    data->append(row1);
    data->append(row2);

    series->dataProxy()->resetArray(data);

    surface->addSeries(series);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(surfaceWidget);
    ui->widget->setLayout(layout);
}

Surface3D::~Surface3D()
{
    delete ui;
}

