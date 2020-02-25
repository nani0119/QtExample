#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(QString(":/qm/main_widget_en"));

    a.installTranslator(&translator);

    MainWindow w;
    w.setTranslator(&translator);
    w.show();
    return a.exec();
}
