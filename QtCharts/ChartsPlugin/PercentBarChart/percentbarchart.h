#ifndef PERCENTBARCHART_H
#define PERCENTBARCHART_H

#include "chartinterface.h"
#include <QMainWindow>

class PercentBarChart : public QMainWindow,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.PercentBarChart")

public:
    PercentBarChart(QWidget *parent = nullptr);
    ~PercentBarChart();

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QChart* chart;
};
#endif // PERCENTBARCHART_H
