#ifndef PIECHART_H
#define PIECHART_H

#include "chartinterface.h"
#include <QMainWindow>

class PieChart : public QMainWindow,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.PieChart")

public:
    PieChart(QWidget *parent = nullptr);
    ~PieChart();

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private slots:
    void onSliceClicked(QPieSlice *slice);
private:
    QChart *chart;
};
#endif // PIECHART_H
