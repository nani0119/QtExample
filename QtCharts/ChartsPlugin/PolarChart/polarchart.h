#ifndef POLARCHART_H
#define POLARCHART_H
#include "chartinterface.h"
#include <QMainWindow>

class ChartView: public QChartView
{
public:
    ChartView(QWidget *parent = nullptr);
};


class PolarChart : public QMainWindow,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.PolarChart")
public:
    PolarChart(QWidget *parent = nullptr);
    ~PolarChart();
    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QPolarChart *chart;
};
#endif // POLARCHART_H
