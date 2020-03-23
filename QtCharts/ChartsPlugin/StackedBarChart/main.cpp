#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackedBarChart w;
    w.show();
    return a.exec();
}
