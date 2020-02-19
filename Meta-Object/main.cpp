#include "mainwindow.h"

#include <QApplication>
#include <QMetaObject>
#include <QMetaClassInfo>
#include <QGenericReturnArgument>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyMainWindow *w = new MyMainWindow;
    const QMetaObject *obj = w->metaObject();
    const QMetaObject *superClass  = obj->superClass();

    qDebug()<<"classInfoCount:" << obj->classInfoCount();

    qDebug()<<"classInfoOffset:" << obj->classInfoOffset();

    qDebug()<<"classInfo: ";
    for(int index = 0; index < obj->classInfoCount(); index++)
    {
        QMetaClassInfo metaClassInfo = obj->classInfo(index);
        qDebug()<<"\t" << index <<":"<< metaClassInfo.name()<<"   " <<  metaClassInfo.value();
    }



    qDebug()<<"className:" << obj->className();

    qDebug()<<"constructorCount:" << obj->constructorCount();

    qDebug()<<"enumeratorCount:" << obj->enumeratorCount();

    qDebug()<< obj->className() << " inherits from " << superClass->className() << ":" << obj->inherits(superClass);

    qDebug()<<"methodCount:" << obj->methodCount();

    qDebug()<<"methodOffset:" << obj->methodOffset();

    qDebug()<<"method: ";
    for(int index = 0; index < obj->methodCount(); ++index)
    {
         qDebug() <<"\t" << index << QString::fromLatin1(obj->method(index).methodSignature());
    }



    qDebug()<<"propertyCount:" << obj->propertyCount();
    w->setProperty(obj->property(0).name(), "newWindow");
    qDebug()<<"index 0 of property name:" << obj->property(0).name();
    QVariant propertyVal =  w->property(obj->property(0).name());
    qDebug()<<"index 0 of property name value:" <<propertyVal.toString();


    int val = 1;
    QGenericReturnArgument ret =  Q_RETURN_ARG(int, val);
    QGenericArgument para = Q_ARG(int, val);
    const char *member = "echo      ";
    obj->invokeMethod(w,member,ret, para);
    qDebug()<<"invokeMethod echo:"<<val;

    qDebug()<<"normalizedSignature:"<<QMetaObject::normalizedSignature(member);

    qDebug()<<"normalizedType:"<<QMetaObject::normalizedType(" int    const  *");

    QObject* newInstance = obj->newInstance(Q_ARG(int, val));
    MyMainWindow *newMyWindow = qobject_cast< MyMainWindow *>(newInstance);
    qDebug()<<"newInstance:"<<newMyWindow->getVal();

    newMyWindow->setWindowTitle("newInstance newMyWindow");
    newMyWindow->show();
    return app.exec();
}
