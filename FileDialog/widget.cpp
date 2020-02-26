#include "widget.h"
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent), pFileDialog(new QFileDialog)
{
    pFileDialog->setOption(QFileDialog::DontUseNativeDialog);
    pFileDialog->setFileMode(QFileDialog::ExistingFiles); //选择多个文件
    pFileDialog->setFilter(QDir::Files);
//    pFileDialog->setNameFilter("翻译文件(*.qm *.ts)");
    QStringList filters;

    filters << "Image files (*.png *.xpm *.jpg)"
    << "Text files (*.txt)"
    << "Any files (*)";
    pFileDialog->setNameFilters(filters);

    pFileDialog->setViewMode(QFileDialog::Detail);

    //pFileDialog->setAcceptMode(QFileDialog::AcceptSave);　//设置保存文件，默认打开文件
    connect(pFileDialog, SIGNAL(filesSelected(const QStringList&)), this ,SLOT(onFilesSelected(const QStringList&)));
    pFileDialog->show();
}

Widget::~Widget()
{
}

void Widget::onFilesSelected(const QStringList &fileList)
{
    qDebug() << fileList;
    qDebug() << "defaultSuffix "<<pFileDialog->defaultSuffix();
    qDebug() << "directory "<<pFileDialog->directory();
    qDebug() << "directoryUrl "<<pFileDialog->directoryUrl();
    qDebug() << "acceptMode "<<pFileDialog->acceptMode();
}

