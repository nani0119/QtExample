#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QDateTimeEdit;
class QLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onDateTimeChanged(const QDateTime&);
private:
    QDateTimeEdit *pCurrentDateTime;
    QDateTimeEdit *pDateTime;
    QDateTimeEdit *pDate;
    QDateTimeEdit *pTime;
    QLabel *pLabel;
};
#endif // MAINWINDOW_H
