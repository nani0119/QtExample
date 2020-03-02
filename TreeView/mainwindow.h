#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTreeView;
class QDirModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onCreateDir();
    void onRemove();
private:
    QTreeView *pTreeView;
    QDirModel *pDirModel;
};
#endif // MAINWINDOW_H
