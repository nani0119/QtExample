#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSplitter;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onHSplitterMoved(int pos, int index);
    void onVSplitterMoved(int pos, int index);

private:
    QSplitter *hSplitter;
    QSplitter *vSplitter;
};
#endif // MAINWINDOW_H
