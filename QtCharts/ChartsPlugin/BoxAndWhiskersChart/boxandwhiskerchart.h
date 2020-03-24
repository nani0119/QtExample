#ifndef BOXANDWHISKERCHART_H
#define BOXANDWHISKERCHART_H
#include "chartinterface.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BoxAndWhiskerChart; }
QT_END_NAMESPACE

class BoxAndWhiskerChart : public QMainWindow, IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.BoxAndWhiskerChart")
public:
    BoxAndWhiskerChart(QWidget *parent = nullptr);
    ~BoxAndWhiskerChart();

private:
    Ui::BoxAndWhiskerChart *ui;

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QChart* chart;
};
#endif // BOXANDWHISKERCHART_H
