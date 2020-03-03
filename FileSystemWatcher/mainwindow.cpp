#include "mainwindow.h"
#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),dirWatcher(new FileSystemWatcher),fileWatcher(new FileSystemWatcher)
{
    QString home =  QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    dirWatcher->addWatchPath(home + "/test");
    fileWatcher->addWatchPath(home + "/test/file");
}

MainWindow::~MainWindow()
{
}

FileSystemWatcher* FileSystemWatcher::pInstance = nullptr;
FileSystemWatcher::FileSystemWatcher(QObject *parent): QObject(parent)
{

}

FileSystemWatcher::~FileSystemWatcher()
{

}

void FileSystemWatcher::addWatchPath(QString path)
{
    qDebug()<<__func__<<":"<<path;
    if(pInstance == nullptr)
    {
        pInstance = new FileSystemWatcher;
        pInstance->pFileSystemWatcher = new QFileSystemWatcher;
        connect(pInstance->pFileSystemWatcher, SIGNAL(directoryChanged(QString)),this, SLOT(onDirectoryChanged(QString)));
        connect(pInstance->pFileSystemWatcher, SIGNAL(fileChanged(QString)),this, SLOT(onFileChanged(QString)));
    }
    qDebug()<<__func__<<":"<<pInstance;
    bool ok;
    ok = pInstance->pFileSystemWatcher->addPath(path);

    QFileInfo file(path);
    if(ok && file.isDir())
    {
        QDir dir(path);
        pInstance->currentContentsMap[path] = dir.entryList(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
        qDebug()<<__func__<<":"<<pInstance->currentContentsMap[path];
    }

}

void FileSystemWatcher::onDirectoryChanged(QString path)
{
    qDebug()<<__func__<<"Directory updated:"<<path;
    QStringList currentEntryList = currentContentsMap[path];

    const QDir dir(path);
    QStringList newEntryList = dir.entryList(QDir::NoDotAndDotDot  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);

    QSet<QString> newDirSet = QSet<QString>::fromList(newEntryList);
    QSet<QString> currentDirSet = QSet<QString>::fromList(currentEntryList);

    QSet<QString> newFiles = newDirSet - currentDirSet;
    QStringList newFileList = newFiles.toList();

    QSet<QString> delFiles = currentDirSet - newFiles;
    QStringList delFileList = delFiles.toList();

    currentContentsMap[path] = newEntryList;
    if(!delFileList.isEmpty()&&!newFileList.isEmpty())
    {
        if(delFileList.count() == 1 && newFileList.count() == 1)
        {
            qDebug()<<QString("File Renamed from %1 to %2").arg(delFileList.first().arg(newFileList.first()));
        }
    }
    else
    {
        if(!newFileList.isEmpty())
        {
            qDebug() << "New Files/Dirs added: " << newFileList;
        }
        if(!delFileList.isEmpty())
        {
            qDebug() << "Files/Dirs deleted: " << delFileList;
        }
    }

}

void FileSystemWatcher::onFileChanged(QString path)
{
    QFileInfo file(path);
    QString strPath = file.absolutePath();
    QString strName = file.fileName();

    qDebug() << QString("The file %1 at path %2 is updated").arg(strName).arg(strPath);

}
