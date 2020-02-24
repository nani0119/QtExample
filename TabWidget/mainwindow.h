#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTabWidget;
class QScrollArea;
class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private slots:
    void onTabWidgetCurrentChanged(int index);
    void onTabWidgetTabBarClicked(int index);
    void onTabWidgetTabBarDoubleClicked(int index);
    void onTabWidgettabCloseRequested(int index);
    void onListWidgetItemClicked(QListWidgetItem* item);
protected:
    QSize sizeHint() const override;
private:
    QTabWidget *pTabWidget;
    QScrollArea *pScrollArea;
    QWidget *pMainPanelScrollAreaWidget;
    QWidget *pLoginScrollAreaWidget;
    QListWidgetItem *mainPanel;
    QListWidgetItem *login;

};
#endif // MAINWINDOW_H
