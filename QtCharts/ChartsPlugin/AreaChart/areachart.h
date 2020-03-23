#ifndef AREACHART_H
#define AREACHART_H
#include "chartinterface.h"
#include <QWidget>

class AreaChart : public QWidget, IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.AreaChart")

public:
    AreaChart(QWidget *parent = nullptr);
    ~AreaChart();

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private slots:
    void onAreaSeriesCliecked(QPointF point);
private:
    QChart* chart;
    QChartView *chartView;
};
#endif // AREACHART_H
