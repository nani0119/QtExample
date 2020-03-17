#include "widget.h"
#include <QDebug>
#include <QDir>
#include <QComboBox>
#include <QVariant>
#include <QVBoxLayout>
#include <QPluginLoader>
#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent), chartInterface(nullptr),myWidget(nullptr),
    layout(new QVBoxLayout),theme(QChart::ChartThemeLight)
{

}

void Widget::loadPlugin(const QString& text)
{
    qDebug()<<__func__<<" "<<text;
    QComboBox* comboBox = qobject_cast<QComboBox *> (sender());
    if(comboBox == nullptr)
    {
        qDebug()<<__func__<<"  error: comboBox is nullptr";
        return;
    }

    QString pluginFile = comboBox->currentData().toString();
    qDebug()<<__func__<<" plugin Path:"<<pluginFile;

    QPluginLoader pluginLoader(pluginFile);

     QObject *plugin = pluginLoader.instance();
     if (plugin)
     {
         chartInterface = qobject_cast<IChartInterface *>(plugin);
         if(chartInterface)
         {
            if(myWidget != nullptr)
            {
                layout->removeWidget(myWidget);
                delete  myWidget;
            }
            chartInterface->echo("hello");
            QObject* obj = chartInterface->getInstance();
            myWidget = qobject_cast<QWidget*>(obj);
            if(myWidget == nullptr)
            {
                qDebug()<<__func__<<"  error: get widget fail";
                return;
            }
            layout->addWidget(myWidget);
            onChartThemeChanged(theme);
            setLayout(layout);
         }

     }
     else
     {
        qDebug()<< "error:" <<pluginLoader.errorString() ;
     }


}

void Widget::onChartThemeChanged(int index)
{
    qDebug()<<__func__<<" "<< index;
    if(chartInterface != nullptr)
    {
        QChart* chart = chartInterface->getChart();
        if(chart != nullptr)
        {
            theme = (enum QChart::ChartTheme)index;
            chart->setTheme(theme);
        }
    }
}
