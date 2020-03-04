#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QListWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onButtonClicked();
private:
    QListWidget *pShowAllTypeIcon;
    QListWidget *pShowFileIcon;
};
#endif // MAINWINDOW_H
