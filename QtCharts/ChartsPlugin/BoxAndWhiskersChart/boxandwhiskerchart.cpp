#include "boxandwhiskerchart.h"
#include "ui_boxandwhiskerchart.h"
#include "boxset.h"
#include <QDebug>


BoxAndWhiskerChart::BoxAndWhiskerChart(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::BoxAndWhiskerChart),chart(new QChart)
{

    ui->setupUi(this);
    QBoxPlotSeries *acmeSeries = new QBoxPlotSeries();
    acmeSeries->setName("Acme Ltd");

    QBoxPlotSeries *boxWhiskSeries = new QBoxPlotSeries();
    boxWhiskSeries->setName("BoxWhisk Inc");

    QFile acmeData(":/data/acme_data.txt");
    if (!acmeData.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<__func__<<":"<<"read acme_data.txt fail";
        return;
    }

    BoxDataReader acmeDataReader(&acmeData);
    while (!acmeDataReader.atEnd()) {
        QBoxSet *set = acmeDataReader.readBox();
        if (set)
        {
            acmeSeries->append(set);
        }
    }


    QFile boxwhiskData(":/data/boxwhisk_data.txt");
    if (!boxwhiskData.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<__func__<<":"<<"read boxwhisk_data.txt fail";
        return;
    }
    BoxDataReader boxwhiskDataReader(&boxwhiskData);
    while (!boxwhiskDataReader.atEnd()) {
        QBoxSet *set = boxwhiskDataReader.readBox();
        if (set)
        {
            boxWhiskSeries->append(set);
        }
    }

    chart->addSeries(acmeSeries);
    chart->addSeries(boxWhiskSeries);
    chart->setTitle("Acme Ltd and BoxWhisk Inc share deviation in 2012");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setMin(15.0);
    chart->axes(Qt::Horizontal).first()->setMax(34.0);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}

BoxAndWhiskerChart::~BoxAndWhiskerChart()
{
    delete ui;
}

QString BoxAndWhiskerChart::echo(const QString &message)
{
    return  message;
}

QString BoxAndWhiskerChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *BoxAndWhiskerChart::getInstance()
{
    return this;
}

QChart *BoxAndWhiskerChart::getChart()
{
    return chart;
}
