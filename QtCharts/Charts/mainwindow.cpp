#include "mainwindow.h"
#include "chartinterface.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getAllPlugin(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAllPlugin(Ui::MainWindow *ui)
{
    QComboBox* comboxBox  = ui->pluginSelectComboBox;
    if(comboxBox == nullptr)
    {
        qDebug()<<"error: "<<"plugin select ComboBox nullptr";
        return;
    }
    QDir pluginsDir(qApp->applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cdUp();
    //切换到插件目录
    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files,QDir::Unsorted))
    {

        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        //qDebug()<<pluginsDir.absoluteFilePath(fileName);

        QObject *pluginObj = pluginLoader.instance();
        if(!pluginObj)
        {

            qDebug()<<"error: "<<pluginLoader.errorString();
        }


        IChartInterface *plugin = qobject_cast<IChartInterface *>(pluginObj);
        if(plugin)
        {
            QString pluginName = plugin->getPluginId();
            //qDebug()<<"plugin:"<<pluginName<<"   path:"<<pluginsDir.absoluteFilePath(fileName);
            comboxBox->addItem(pluginName,pluginsDir.absoluteFilePath(fileName));
        }

    }
}

