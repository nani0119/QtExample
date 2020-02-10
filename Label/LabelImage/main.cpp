#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel* pLabel = new QLabel();

    QPixmap pixmap(":/img/logo");
    pLabel->setPixmap(pixmap);
    pLabel->setFixedSize(50,50);
    pLabel->setScaledContents(true);

    pLabel->show();


    return a.exec();
}
