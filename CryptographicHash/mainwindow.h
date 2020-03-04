#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QFormLayout;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onStrCalcButtonClicked();
    void onFileSelectButtonClicked();
    void onFileCalcButtonClicked();
private:
    QWidget *createFileHashTab();
    QWidget* createStrHashTab();
    QFormLayout* createFormlayout();
    void clearLineEdit(QWidget* widget);
    void calc(QWidget* widget,const char* buf, int len);
    void calc(QWidget* widget,QByteArray &data);
    QWidget *fileHash;
    QWidget *strHash;
};
#endif // MAINWINDOW_H
