#include <QCoreApplication>
#include <QDBusInterface>
#include <QDBusReply>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建QDBusInterface接口
    QDBusInterface interface("com.example.servicetest",
                             "/servicetest/objects",
                             "com.example.servicetest.value",
                                 QDBusConnection::sessionBus());

    if (!interface.isValid())
      {
          qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
          exit(1);
      }

    //调用远程的value方法
    QDBusReply<void> reply = interface.call("setValue",15);


    if (reply.isValid())
    {
        qDebug() << "QDBusInterface：SetValue method called successfully!";
    }
    else
    {
        qDebug() << "QDBusInterface：SetValue method called failed!";
    }

    QDBusReply<int> valReply = interface.call("value");
    if (valReply.isValid())
    {
        int value = valReply.value();
        qDebug() << QString("value =  %1").arg(value);
    }
    else
    {
        qDebug() << "QDBusInterface：value method called failed!";
    }

    return a.exec();
}
