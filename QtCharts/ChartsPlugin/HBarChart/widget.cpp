#include "widget.h"
#include <QChart>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QHorizontalBarSeries>
#include <QVBoxLayout>

HBarChart::HBarChart(QWidget *parent)
    : QWidget(parent)
{
    QBarSet *set0 = new QBarSet("Jane");
    *set0 << 1 << 2 << 3 << 4 << 5 << 6;

    QBarSet *set1 = new QBarSet("John");
    *set1 << 5 << 2 << 6 << 4 << 3 << 7;

    QHorizontalBarSeries *hBarseries = new QHorizontalBarSeries;
    hBarseries->append(set0);
    hBarseries->append(set1);

    chart = new QChart;
    chart->addSeries(hBarseries);
    chart->setTitle("Simple horizontal barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QStringList category;
    category<<"Jan"<<"Feb"<<"Mar"<<"Apr"<<"May"<<"Jun";
    QBarCategoryAxis *yAixs = new QBarCategoryAxis();
    yAixs->setCategories(category);
    chart->addAxis(yAixs,Qt::AlignLeft);
    hBarseries->attachAxis(yAixs);


    QValueAxis *xAixs = new QValueAxis();
    xAixs->setRange(0,15);
    xAixs->applyNiceNumbers();
    chart->addAxis(xAixs,Qt::AlignBottom);
    hBarseries->attachAxis(xAixs);


    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView;
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(chartView);
    setLayout(layout);
}

HBarChart::~HBarChart()
{
}

QString HBarChart::echo(const QString &message)
{
    return message;
}

QString HBarChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *HBarChart::getInstance()
{
    return this;
}

QChart *HBarChart::getChart()
{
    return chart;
}

