#include "linechart.h"
#include <QVBoxLayout>
#include <QBarSeries>
#include <QBarSet>
#include <QLineSeries>
#include <QSplineSeries>
#include <QValueAxis>
#include <QBarCategoryAxis>

LineChart::LineChart(QWidget *parent):QWidget(parent), chart(new QChart)
{
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");

    *set0 << 10 << 12 << 3 << 8 << 5 << 6;
    *set1 << 7 << 13 << 3 << 4 << 7 << 7;

    QBarSeries *barSeries = new QBarSeries;
    barSeries->append(set0);
    barSeries->append(set1);

    QLineSeries *lineSeries = new QLineSeries;
    lineSeries->setName(set0->label());
    for(int i = 0; i < set0->count(); i++)
    {
        lineSeries->append(i,set0->at(i)+10);
    }

    QSplineSeries *splineSeries = new QSplineSeries;
    splineSeries->setName(set1->label());
    for(int i = 0; i < set1->count(); i++)
    {
        splineSeries->append(i,set1->at(i)+10);
    }

    chart->addSeries(barSeries);
    chart->addSeries(lineSeries);
    chart->addSeries(splineSeries);


    chart->setTitle("Line and barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList category;
    category<<"Jan"<<"Feb"<<"Mar"<<"Apr"<<"May"<<"Jun";
    QBarCategoryAxis *xAxis = new QBarCategoryAxis();
    xAxis->setCategories(category);
    xAxis->setRange(QString("Jan"), QString("Jun"));
    chart->addAxis(xAxis,Qt::AlignBottom);

    barSeries->attachAxis(xAxis);
    // lineSeries
    lineSeries->attachAxis(xAxis);
    splineSeries->attachAxis(xAxis);



    QValueAxis *yAxix = new QValueAxis;
    yAxix->setRange(0,25);
    yAxix->applyNiceNumbers();
    yAxix->setVisible(false);
    chart->addAxis(yAxix, Qt::AlignLeft);

    barSeries->attachAxis(yAxix);
    // lineSeries
    lineSeries->attachAxis(yAxix);
    splineSeries->attachAxis(yAxix);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView;
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(chartView);
    setLayout(layout);
}

QString LineChart::echo(const QString &message)
{
    return  message;
}

QString LineChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *LineChart::getInstance()
{
    return this;
}

QChart *LineChart::getChart()
{
    return chart;
}


