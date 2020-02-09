#include <QApplication>
#include <QMainWindow>
#include <QDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow* pMainWindow = new QMainWindow();
    pMainWindow->setWindowTitle(QStringLiteral("主界面"));
    pMainWindow->show();

    QDialog* pDialog = new QDialog(pMainWindow);
    pDialog->setWindowTitle(QStringLiteral("非模式对话框"));
    pDialog->show();

    pMainWindow->setWindowTitle(QStringLiteral("主界面-非模式对话框"));
    qDebug()<< QStringLiteral("立即运行");

    return a.exec();
}
