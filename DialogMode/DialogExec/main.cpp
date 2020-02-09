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
    pDialog->setWindowTitle(QStringLiteral("模式对话框"));
    pDialog->exec();

    pMainWindow->setWindowTitle(QStringLiteral("主界面-模式对话框"));
    qDebug()<< QStringLiteral("关闭模态对话框以后，可以继续向下执行");

    return a.exec();
}
