#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QListWidget;
class QListWidgetItem;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onListWidgetItemClicked(QListWidgetItem* item);
    void onListWidgetCurrentItemChanged(QListWidgetItem*,QListWidgetItem*);
    void onListStyleRadioButtonClicked();
    void onIconStyleRadioButtonClicked();
private:
    QLabel *pLabel;
    QListWidget *pListWidget;
};
#endif // MAINWINDOW_H
