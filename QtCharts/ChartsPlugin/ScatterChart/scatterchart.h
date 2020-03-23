#ifndef SCATTERCHART_H
#define SCATTERCHART_H

#include "chartinterface.h"
#include <QWidget>

class ScatterChart : public QWidget,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.ScatterChart")

public:
    ScatterChart(QWidget *parent = nullptr);
    ~ScatterChart();

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QChart* chart;
};
#endif // SCATTERCHART_H
