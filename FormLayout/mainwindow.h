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
private:
    QFormLayout *pFormLayout;
};
#endif // MAINWINDOW_H
