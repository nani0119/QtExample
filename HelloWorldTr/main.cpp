#include <QApplication>
#include <QLabel>
#include <QTranslator>

#ifdef USE_DEBUG
#include <QDebug>
#include <QDir>
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator  translator;
    translator.load("HelloWorldTr_zh_CN");
    app.installTranslator(&translator);
    QLabel label(QObject::tr("Hello World!"));
    label.setAlignment(Qt::AlignCenter);
    label.resize(400, 300);
    label.show();

#ifdef USE_DEBUG
    qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath();
    qDebug()<<"current currentPath: "<<QDir::currentPath();
#endif
    return app.exec();
}
