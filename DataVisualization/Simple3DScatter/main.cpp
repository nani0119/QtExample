#include "scatter3d.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scatter3D w;
    w.show();
    return a.exec();
}
