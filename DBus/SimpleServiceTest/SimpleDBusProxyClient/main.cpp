#include <QCoreApplication>
#include "valueInterface.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 初始化自动生成的Proxy类com::example::servicetest::value
    com::example::servicetest::value proxyTest("com.example.servicetest",
                                               "/servicetest/objects",
                                               QDBusConnection::sessionBus());

    // 调用value方法
    QDBusPendingReply<void> reply = proxyTest.setValue(16);
    //qdbusxml2cpp生成的Proxy类是采用异步的方式来传递Message，
    //所以需要调用waitForFinished来等到Message执行完成
    reply.waitForFinished();
    if (reply.isValid())
    {
        qDebug() << "SimpleDBusProxyClient: setValue method called successfully!";
    }
    else
    {
        qDebug() << "SimpleDBusProxyClient: setValue method called failed!";
    }

    QDBusPendingReply<int> valueReply = proxyTest.value();
    valueReply.waitForFinished();
    if (valueReply.isValid())
    {
        int value = valueReply.value();
        qDebug() << QString("value =  %1").arg(value);
    }
    else
    {
        qDebug() << "SimpleDBusProxyClient:value method called failed!";
    }
    return a.exec();
}
