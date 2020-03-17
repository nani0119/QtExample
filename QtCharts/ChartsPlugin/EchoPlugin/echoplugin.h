#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QWidget>
#include <chartinterface.h>
#include <QtCharts>
using namespace QtCharts;

class QLabel;
class EchoPlugin : public QWidget, IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.EchoInterface")
private slots:
    void onSendButtonClicked();
public:
    explicit EchoPlugin(QWidget *parent = nullptr);
    QString echo(const QString &message);
    QString getPluginId();
    QObject* getInstance();
    QChart* getChart();
private:
    QLabel *echoAnswer;
};

#endif // ECHOPLUGIN_H
