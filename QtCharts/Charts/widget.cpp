#include "widget.h"
#include <QDebug>
#include <QDir>
#include <QComboBox>
#include <QVariant>
#include <QGridLayout>
#include <QPluginLoader>

Widget::Widget(QWidget *parent) : QWidget(parent), chart(nullptr),myWidget(nullptr)
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
         chart = qobject_cast<IChartInterface *>(plugin);
         if(chart)
         {
            qDebug()<< "echo:" << chart->echo("hello");
            QObject* obj = chart->getInstance();
            myWidget = qobject_cast<QWidget*>(obj);
            if(myWidget == nullptr)
            {
                qDebug()<<__func__<<"  error: get widget fail";
                return;
            }
            QGridLayout* layout = new QGridLayout;
            layout->addWidget(myWidget);
            setLayout(layout);
         }

     }
     else
     {
        qDebug()<< "error:" <<pluginLoader.errorString() ;
     }


}
