#ifndef DONUTCHART_H
#define DONUTCHART_H
#include "chartinterface.h"
#include <QMainWindow>

class DonutChart : public QMainWindow,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.AreaChart")

public:
    DonutChart(QWidget *parent = nullptr);
    ~DonutChart();
private slots:
    void onSliceClicked(QPieSlice *slice);
    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QChart* chart;
};
#endif // DONUTCHART_H
