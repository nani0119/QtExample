#ifndef LINECHART_H
#define LINECHART_H

#include "chartinterface.h"
#include <QWidget>

class  LineChart:public QWidget,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.LineChart")
public:
    LineChart(QWidget* parent = nullptr);
private:
    QChart * chart;

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
};

#endif // LINECHART_H
