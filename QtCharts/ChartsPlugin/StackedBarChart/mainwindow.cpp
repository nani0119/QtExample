#include "mainwindow.h"
#include <QDebug>

StackedBarChart::StackedBarChart(QWidget *parent)
    : QMainWindow(parent), chart(new QChart)
{

    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    QStackedBarSeries *barSeries = new QStackedBarSeries;
    barSeries->append(set0);
    barSeries->append(set1);
    barSeries->append(set2);
    barSeries->append(set3);
    barSeries->append(set4);

    chart->addSeries(barSeries);
    chart->setTitle("Simple stackedbarchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";

    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->setCategories(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    //axisY->setRange(0,30);
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView;
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);
}

StackedBarChart::~StackedBarChart()
{
}

QString StackedBarChart::echo(const QString &message)
{
    return message;
}

QString StackedBarChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *StackedBarChart::getInstance()
{
    return this;
}

QChart *StackedBarChart::getChart()
{
    return chart;
}

