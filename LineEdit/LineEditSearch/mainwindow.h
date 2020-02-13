#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLineEdit;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onTrggered(bool);
    void onTextChange(const QString&);
    void onReturnPressed();
private:
    QLineEdit *pSearchLineEdit;
    QLabel    *pLabel;
};
#endif // MAINWINDOW_H
