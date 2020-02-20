#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
class QDateEdit;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QString myDate READ myDate WRITE setMyDate NOTIFY myDateChanged RESET unsetMyDate DESIGNABLE true STORED true)
    Q_PROPERTY(QString dateText MEMBER m_date  NOTIFY dateTextChanged)
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString myDate();
    void setMyDate(QString);
    void unsetMyDate();
signals:
    void myDateChanged(QString);
    void dateTextChanged(QString);
private slots:
    void onDateChanged(QDate date);
    void onDateMainWindowChanged(QString date);
    void onDateTextChanged(QString);
private:
    QDateEdit* pDateEdit;
    QString dateStr;
    QString m_date;
};
#endif // MAINWINDOW_H
