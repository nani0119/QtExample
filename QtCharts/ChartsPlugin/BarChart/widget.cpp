#include "chartstooltip.h"
#include "widget.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QtCharts>

BarChart::BarChart(QWidget *parent)
    : QWidget(parent), chart(new QChart),tooltip(nullptr)
{

    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 2 << 6 << 4 << 3 << 7;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(chartView);
    setLayout(layout);

    connect(series,SIGNAL(hovered(bool, int , QBarSet *)),this, SLOT(onBarSeriesHovered(bool, int , QBarSet *)));
    connect(series,SIGNAL(clicked(int , QBarSet *)),this, SLOT(onBarSeriesClicked(int , QBarSet *)));
}

BarChart::~BarChart()
{

}

QString BarChart::echo(const QString &message)
{
    return message;
}

QString BarChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *BarChart::getInstance()
{
    return this;
}

QChart *BarChart::getChart()
{
    return chart;
}

void BarChart::onBarSeriesHovered(bool status, int index, QBarSet *set)
{
    Q_UNUSED(index)
    Q_UNUSED(set)
    if(status == false)
    {
        tooltip->hide();
        return;
    }
}


void BarChart::onBarSeriesClicked(int index, QBarSet *set)
{
    qDebug()<<__func__<<" index: "<< index << "  value: "<<set->at(index);

    if(tooltip == nullptr)
    {
        tooltip = new ChartToolTip(chart);
    }

    QPoint globalCursorPoint = cursor().pos();
    qDebug()<<__func__<<" cursor pos:" << globalCursorPoint;
    QPoint chartViewPoint = mapFromGlobal(globalCursorPoint);
    qDebug()<<__func__<<" chartViewPoint:" << chartViewPoint;
    QPointF sencePoint = chartView->mapToScene(chartViewPoint);
    qDebug()<<__func__<<" sencePoint:" << sencePoint;
    QPointF chartPoint = chart->mapFromScene(sencePoint);
    qDebug()<<__func__<<" chartPoint:" << chartPoint;
    QPointF seriesPoint = chart->mapToValue(chartPoint);
    qDebug()<<__func__<<" seriesPoint:" << seriesPoint;
    //                   mapFromGlobal               mapToScene             mapFromScene               mapToValue
    // globalCursorPoint--------------->charViewPoint----------->scenePoint--------------->chartPoint-------------->seriesPoint
    //                                                                                                                  |
    //                                                                                                                  | mapToPosition
    //                                                                      mapFromParent                               |
    //                                                       toolTipPoint<----------------chartPoint<------------------
    tooltip->setAnchor(seriesPoint);
    tooltip->setText(QString("index: %1 \nvalue: %2 ").arg(index).arg(set->at(index)));
    tooltip->setZValue(11);
    tooltip->updateGeometry();
    tooltip->show();
}

