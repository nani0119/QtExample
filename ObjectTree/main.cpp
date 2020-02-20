#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.dumpObjectTree();
    a.dumpObjectInfo();
    w.show();
    return a.exec();
}
