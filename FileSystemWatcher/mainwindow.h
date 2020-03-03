#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

class QFileSystemWatcher;

class FileSystemWatcher : public QObject
{
    Q_OBJECT
public:
    FileSystemWatcher(QObject *parent = nullptr);
    ~FileSystemWatcher();
    void addWatchPath(QString path);
private slots:
    void onDirectoryChanged(QString);
    void onFileChanged(QString);
private:
    static FileSystemWatcher *pInstance;
    QFileSystemWatcher *pFileSystemWatcher;
    QMap<QString, QStringList> currentContentsMap;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    FileSystemWatcher *dirWatcher;
    FileSystemWatcher *fileWatcher;
};
#endif // MAINWINDOW_H
