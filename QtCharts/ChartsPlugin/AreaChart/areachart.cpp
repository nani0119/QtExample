#include "areachart.h"
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QVBoxLayout>
#include <QDebug>

AreaChart::AreaChart(QWidget *parent)
    : QWidget(parent),chart(new QChart)
{
    QLineSeries *lineSeries0 = new QLineSeries;

    *lineSeries0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                   << QPointF(16, 7) << QPointF(18, 5);

    QLineSeries *lineSeries1 = new QLineSeries;
    *lineSeries1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
              << QPointF(16, 4) << QPointF(18, 3);


    QAreaSeries *areaSeries = new QAreaSeries;
    areaSeries->setName("areaSeries");
    areaSeries->setUpperSeries(lineSeries0);
    areaSeries->setLowerSeries(lineSeries1);

    QPen pen(0x059605);
    pen.setWidth(3);
    areaSeries->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0,0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    areaSeries->setBrush(gradient);


    chart->addSeries(areaSeries);
    chart->setTitle("simple areachart example");

    QValueAxis *xAxis = new QValueAxis;
    xAxis->setRange(0,20);
    chart->addAxis(xAxis,Qt::AlignBottom);
    areaSeries->attachAxis(xAxis);

    QValueAxis *yAxis = new QValueAxis;
    yAxis->setRange(0,10);
    chart->addAxis(yAxis,Qt::AlignLeft);
    areaSeries->attachAxis(yAxis);

    chartView = new QChartView;
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setChart(chart);

    connect(areaSeries, SIGNAL(clicked(QPointF)), this, SLOT(onAreaSeriesCliecked(QPointF)));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(chartView);
    setLayout(layout);

}

AreaChart::~AreaChart()
{
}

QString AreaChart::echo(const QString &message)
{
    return  message;
}

QString AreaChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *AreaChart::getInstance()
{
    return this;
}

QChart *AreaChart::getChart()
{
    return chart;
}

void AreaChart::onAreaSeriesCliecked(QPointF point)
{
    qDebug()<<__func__<<"point:"<<point;

    QPoint cusorPoint = cursor().pos();
    QPoint chartViewPoint = mapFromGlobal(cusorPoint);
    qDebug()<<__func__<<"chartViewPoint:"<<chartViewPoint;

    QPointF sencePoint = chartView->mapToScene(chartViewPoint);
    qDebug()<<__func__<<"sencePoint:"<<sencePoint;

    QPointF chartPoint = chart->mapFromScene(sencePoint);
    qDebug()<<__func__<<"chartPoint:"<<chartPoint;

    QPointF seriesPoint = chart->mapToValue(chartPoint);
    qDebug()<<__func__<<"seriesPoint:"<<seriesPoint;

    QPointF mapToPosition = chart->mapToPosition(point);
    qDebug()<<__func__<<"chartMapToPositionPoint:"<<mapToPosition;
     qDebug()<<"==========================================";

}

