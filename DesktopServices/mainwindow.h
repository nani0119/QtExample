#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
class QPushButton;
class QLineEdit;

class MyHelpHandler: public QObject
{
    Q_OBJECT
public:
    MyHelpHandler(QObject* parent = nullptr);
    ~MyHelpHandler();
private slots:
    void  onHelpHandlerOpenMail(QUrl url);
    void  onHelpHandlerOpenTxt(QUrl url);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onOpenUrl();
    void onOpenMail();
    void onOpenTxt();
private:
    QPushButton *pOpenUrlButton;
    QLineEdit *pOpenUrlLineEdit;
    QPushButton *pOpenMailButton;
    QLineEdit *pOpenMailLineEdit;
    QPushButton *pOpenTxtButton;
    QLineEdit *pOpenTxtLineEdit;
    MyHelpHandler *myHelpHandler;

};
#endif // MAINWINDOW_H
