#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>

void delayMs(long msec)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<msec)
    {
        QCoreApplication::processEvents();
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MySplashScreen* splash = new MySplashScreen;
    splash->setPixmap(QPixmap(":/img/splash"));
    splash->show();
    QObject::connect(splash, SIGNAL(messageChanged(const QString &)), splash, SLOT(onMessageChanged(const QString&)));

    splash->showMessage(QObject::tr("Setting up the main window..."),
                                   Qt::AlignRight | Qt::AlignBottom, Qt::black);

    MainWindow w;

    delayMs(1500);

    splash->showMessage(QObject::tr("show main window..."),
                                  Qt::AlignRight | Qt::AlignBottom, Qt::black);
    delayMs(1500);

    splash->showMessage(QObject::tr("connect newwork..."),
                                  Qt::AlignRight | Qt::AlignBottom, Qt::black);

    delayMs(1500);

    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}
