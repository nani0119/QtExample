#include "widget.h"
#include <QtCharts>
//#include <QChart>
#include <QVBoxLayout>
#include <QDebug>
using namespace QtCharts;

BarChart::BarChart(QWidget *parent)
    : QWidget(parent), chart(new QChart)
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

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(chartView);
        setLayout(layout);

        connect(series,SIGNAL(clicked(int, QBarSet*)), this, SLOT(onBarSeriesClicked(int,QBarSet*)));
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

void BarChart::onBarSeriesClicked(int index, QBarSet *set)
{
    qDebug()<<__func__<<" index: "<< index << "  value: "<<set->at(index);
}

