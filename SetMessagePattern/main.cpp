#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString messagePattern = "[%{time yyyy-MM-dd hh:mm:ss.zzz t}";
    messagePattern += " %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] ";
    messagePattern += " %{pid}:%{threadid} ";
    messagePattern += " %{file}:%{line} ";
    messagePattern += " %{function} :%{message}";

    qSetMessagePattern(messagePattern);
    MainWindow w;
    qDebug("This is a debug message.");
    qInfo("This is a info message.");
    qWarning("This is a warning message.");
    qCritical("This is a critical message.");

    w.show();
    return a.exec();
}
