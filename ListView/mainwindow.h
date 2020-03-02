#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QListView;
class QStringListModel;
class QLabel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onInsertButtonClicked();
    void onDelClicked();
    void onShowClicked();
private:
    QListView *pListView;
    QStringListModel *pStringListModel;
    QLabel* pLabel;
    QStringList *pStringList;
};
#endif // MAINWINDOW_H
