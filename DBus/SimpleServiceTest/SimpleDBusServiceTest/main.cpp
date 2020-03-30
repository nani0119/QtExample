#include "servicetest.h"
#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QDebug>
#include <QtDBus/QDBusError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDBusConnection connection = QDBusConnection::sessionBus();

    if(!connection.registerService("com.example.servicetest"))
    {
        qDebug() << "error:" << connection.lastError().message();
        exit(-1);
    }

    ServiceTest object(60);

    connection.registerObject("/servicetest/objects", &object, QDBusConnection::ExportAllSlots);

    return a.exec();
}
