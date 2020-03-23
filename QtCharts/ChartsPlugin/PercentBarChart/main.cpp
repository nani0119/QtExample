#include "percentbarchart.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PercentBarChart w;
    w.show();
    return a.exec();
}
