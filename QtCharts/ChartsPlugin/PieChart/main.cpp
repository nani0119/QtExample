#include "piechart.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PieChart w;
    w.show();
    return a.exec();
}
