#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    switch (type)
    {
    case QtDebugMsg:
        qDebug()<<context.function <<"  "<<context.file<<":"<<context.line<<"  " << msg;
        break;
    case QtInfoMsg:
         qInfo()<<context.function <<"  "<<context.file<<":"<<context.line<<"  " << msg;
        break;
    case QtWarningMsg:
        qWarning()<< context.function <<"  "<<context.file<<":"<<context.line<<"  " << msg;
        break;
    case QtCriticalMsg:
        qCritical()<< context.function <<"  "<<context.file<<":"<<context.line<<"  " << msg;
        break;
    case QtFatalMsg:
         fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", msg.toLocal8Bit().constData(), context.file, context.line, context.function);
         abort();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(myMessageOutput);
    MainWindow w;

    qDebug("This is a debug message.");
    qWarning("This is a warning message.");
    qCritical("This is a critical message.");
    qFatal("This is a fatal message.");

    w.show();
    return a.exec();
}
