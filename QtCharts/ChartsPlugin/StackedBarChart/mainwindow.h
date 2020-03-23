#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "chartinterface.h"
#include <QMainWindow>

class StackedBarChart : public QMainWindow,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.StackedBarChart")

public:
    StackedBarChart(QWidget *parent = nullptr);
    ~StackedBarChart();

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QChart *chart;
};
#endif // MAINWINDOW_H
