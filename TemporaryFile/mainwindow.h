#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//class QTemporaryFile;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QLabel *pLabel;
};
#endif // MAINWINDOW_H
