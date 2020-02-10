#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel* pLabel = new QLabel();

    QMovie* pMovie = new QMovie(":/img/movie");
    pLabel->setMovie(pMovie);
    pLabel->setFixedSize(300,250);
    pLabel->setScaledContents(true);
    pMovie->start();
    pLabel->show();


    return a.exec();
}
