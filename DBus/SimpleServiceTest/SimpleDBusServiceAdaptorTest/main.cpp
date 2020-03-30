#include "servicevaluetest.h"
#include "valueadaptor.h"
#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QDebug>
#include <QtDBus/QDBusError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //================================================
    //使用adaptor注册继承自com.example.servicetestAdapter.xml的object,裁剪了ServiceValueTest某些函数

    QDBusConnection adaptorConnection = QDBusConnection::sessionBus();
    ServiceValueTest adaptorObject(50);
    ValueAdaptorAdaptor valueAdaptor(&adaptorObject);
    if (!adaptorConnection.registerService("com.example.servicetestadaptor"))
    {
        qDebug() << adaptorConnection.lastError().message();
        exit(1);
    }
    //not valueAdaptor
    adaptorConnection.registerObject("/test/objects", &adaptorObject);

    return a.exec();
}
