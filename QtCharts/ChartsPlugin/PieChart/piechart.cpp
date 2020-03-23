#include "piechart.h"
#include <QDebug>

PieChart::PieChart(QWidget *parent)
    : QMainWindow(parent),chart(new QChart)
{
    QPieSeries *pieSeries = new QPieSeries;
    pieSeries->append("Jane", 1);
    pieSeries->append("Joe", 2);
    pieSeries->append("Andy", 3);
    pieSeries->append("Barbara", 4);
    pieSeries->append("Axel", 5);

    //QPieSlice *slice = pieSeries->slices().at(0);
    //onSliceClicked(slice);

    chart->addSeries(pieSeries);
    chart->setTitle("a pie chart example");
    chart->setAnimationOptions(QChart::AllAnimations);

    chart->legend()->setVisible(false);

    QChartView *chartView = new QChartView;
    chartView->setChart(chart);
    chartView->setRenderHints(QPainter::Antialiasing);
    connect(pieSeries, SIGNAL(clicked(QPieSlice *)), this, SLOT(onSliceClicked(QPieSlice*)));

    setCentralWidget(chartView);
}

PieChart::~PieChart()
{
}

QString PieChart::echo(const QString &message)
{
    return  message;
}

QString PieChart::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QObject *PieChart::getInstance()
{
    return this;
}

QChart *PieChart::getChart()
{
    return chart;
}

void PieChart::onSliceClicked(QPieSlice *slice)
{

    QPieSeries *pieSeries = slice->series();
    for(int i = 0; i < pieSeries->count(); i++)
    {
        if(pieSeries->slices().at(i)->isExploded())
        {
            pieSeries->slices().at(i)->setExploded(false);
            pieSeries->slices().at(i)->setLabelVisible(false);
        }
    }

    slice->setExploded();
    QStringList list = slice->label().split(":");
    QString label = list[0] + ":" + QString("%1").arg(slice->value());
    slice->setLabel(label);
    slice->setLabelVisible();
    qDebug()<<slice->value();
}
