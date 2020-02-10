#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel* pLabelUrl1;
    QLabel* pLabelUrl2;
    QHBoxLayout* layout;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openUrl(const QString &line);
};
#endif // MAINWINDOW_H
