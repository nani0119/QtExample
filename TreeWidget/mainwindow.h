#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTreeWidget;
class QLabel;
class QFileDialog;
class QTreeWidgetItem;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onClick();
    void onFileDialogFileSelected(const QString& file);
    void onCurrentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
private:
    void travelDir(QTreeWidgetItem *parent,QString path);
    QLabel *pLabel;
    QFileDialog *pFileDialog;
    QTreeWidget *pTreeWidget;
    QString dir;
};
#endif // MAINWINDOW_H
