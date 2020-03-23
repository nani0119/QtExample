#include "polarchart.h"
#include <QRandomGenerator>
PolarChart::PolarChart(QWidget *parent)
    : QMainWindow(parent), chart(new QPolarChart)
{

    const int angularMin = -100;
    const int angularMax = 100;

    const int radialMin = 0;
    const int radialMax = 100;

    const int angularTickCount = 6;

//    QSplineSeries *series2 = new QSplineSeries();
//    series2->setName("line");
//    for (int i = angularMin; i <= angularMax; i += 10)
//        series2->append(i, (i / radialMax) * radialMax);

    QLineSeries *series3 = new QLineSeries();
    QLineSeries *series4 = new QLineSeries();

    series3->setName("star outer");
    series4->setName("star inner");
    qreal ad = (angularMax - angularMin) / (angularTickCount -1);
    int first = 0;
    for(int i = 0; i < angularTickCount-1; i++)
    {
        int val = QRandomGenerator::global()->bounded(radialMin,radialMax);
        if(i == 0)
        {
            first = val;
        }
        series3->append(angularMin+ad*i, val);
        series4->append(angularMin+ad*i,radialMin);
    }
    series3->append(angularMin+(angularTickCount-1)*ad,first);
    series4->append(angularMin+(angularTickCount-1)*ad,radialMin);

    QAreaSeries *series5 = new QAreaSeries();
    series5->setName("star area");
    series5->setUpperSeries(series3);
    series5->setLowerSeries(series4);
    series5->setOpacity(0.5);
    series5->setPen(QColor(Qt::green));
    series5->setBrush(QColor(Qt::green));

//    chart->addSeries(series2);
//    chart->addSeries(series3);
//    chart->addSeries(series4);
    chart->addSeries(series5);
    chart->setTitle("a polor chart example");

//    QValueAxis *angularAxis = new QValueAxis();
//    angularAxis->setTickCount(6);
//    angularAxis->setLabelFormat("%.1f");
//    angularAxis->setRange(angularMin,angularMax);
//    //false
//    angularAxis->setVisible(false);
//    chart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

    QCategoryAxis *angularCategoryAxis = new QCategoryAxis;
    angularCategoryAxis->setTickCount(6);
    angularCategoryAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    angularCategoryAxis->setRange(-100,100);
    angularCategoryAxis->setStartValue(-100);
    angularCategoryAxis->append("道",-100);
    angularCategoryAxis->append("场",-60);
    angularCategoryAxis->append("事", -20);
    angularCategoryAxis->append("时", 20);
    angularCategoryAxis->append("人", 60);
    chart->addAxis(angularCategoryAxis, QPolarChart::PolarOrientationAngular);


    QValueAxis *radialAxis = new QValueAxis();
    radialAxis->setLabelsVisible(true);
    radialAxis->setTickCount(11);
    radialAxis->setLabelFormat("%d");
    radialAxis->setRange(radialMin,radialMax);

    chart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);

    //series2->attachAxis(angularAxis);
    //series2->attachAxis(radialAxis);

//    series3->attachAxis(angularAxis);
//    series3->attachAxis(radialAxis);
//    series4->attachAxis(angularAxis);
//    series4->attachAxis(radialAxis);
//      series5->attachAxis(angularAxis);
      series5->attachAxis(angularCategoryAxis);
      series5->attachAxis(radialAxis);

    chart->legend()->setVisible(false);

    ChartView *chartView = new ChartView;
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);

}

PolarChart::~PolarChart()
{
}


QString PolarChart::echo(const QString &message)
{
    return  message;
}

QString PolarChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *PolarChart::getInstance()
{
    return this;
}

QChart *PolarChart::getChart()
{
    return chart;
}

ChartView::ChartView(QWidget *parent):QChartView(parent)
{

}
