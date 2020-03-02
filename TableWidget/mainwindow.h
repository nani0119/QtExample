#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTableWidget;
class QTableWidgetItem;
class QLabel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onClicked();
    void onCurrentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);
private:
    QLabel *pLabel;
    QTableWidget* pTableWidget;
};
#endif // MAINWINDOW_H
