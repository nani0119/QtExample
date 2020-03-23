#include "scatterchart.h"
#include <QVBoxLayout>
#include <QDebug>

ScatterChart::ScatterChart(QWidget *parent)
    : QWidget(parent)
{
     QScatterSeries *series0 = new QScatterSeries();
     series0->setName("scatter1");
     series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
     series0->setMarkerSize(10.0);

     series0->append(0, 6);
     series0->append(2, 4);
     series0->append(3, 8);
     series0->append(7, 4);
     series0->append(10, 5);

     QScatterSeries *series1 = new QScatterSeries();
     series1->setName("scatter2");
     series1->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
     series1->setMarkerSize(15.0);
     *series1 << QPointF(1, 1) << QPointF(3, 3) << QPointF(7, 6) << QPointF(8, 3) << QPointF(10, 2);

     QScatterSeries *series2 = new QScatterSeries();
     series2->setName("scatter3");
     series2->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
     series2->setMarkerSize(30.0);
     *series2 << QPointF(1, 5) << QPointF(4, 6) << QPointF(6, 3) << QPointF(9, 5);

     QPainterPath starPath;
     starPath.moveTo(28, 15);
     for (int i = 1; i < 5; ++i) {
         starPath.lineTo(14 + 14 * qCos(0.8 * i * M_PI),
                         15 + 14 * qSin(0.8 * i * M_PI));
     }
     starPath.closeSubpath();

     QImage star(30, 30, QImage::Format_ARGB32);
     star.fill(Qt::transparent);

     QPainter painter(&star);
     painter.setRenderHint(QPainter::Antialiasing);
     painter.setPen(QRgb(0xf6a625));
     painter.setBrush(painter.pen().color());
     painter.drawPath(starPath);

     series2->setBrush(star);
     series2->setPen(QColor(Qt::transparent));


     chart = new QChart;
     chart->setTitle("Simple scatterchart example");
     chart->addSeries(series0);
     chart->addSeries(series1);
     chart->addSeries(series2);

     QValueAxis *xAxis = new QValueAxis;
     xAxis->setRange(-2,15);
     chart->addAxis(xAxis,Qt::AlignBottom);
     series0->attachAxis(xAxis);
     series1->attachAxis(xAxis);
     series2->attachAxis(xAxis);

     QValueAxis *yAxis = new QValueAxis;
     yAxis->setRange(0,15);
     chart->addAxis(yAxis,Qt::AlignLeft);
     series0->attachAxis(yAxis);
     series1->attachAxis(yAxis);
     series2->attachAxis(yAxis);

     chart->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);

     QChartView *chartView = new QChartView;
     chartView->setChart(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(chartView);
     setLayout(layout);
}

ScatterChart::~ScatterChart()
{
}

QString ScatterChart::echo(const QString &message)
{
    return message;
}

QString ScatterChart::getPluginId()
{
    const QMetaObject* obj = metaObject();
    return obj->className();
}

QObject *ScatterChart::getInstance()
{
    return this;
}

QChart *ScatterChart::getChart()
{
    return chart;
}

