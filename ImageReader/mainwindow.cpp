#include "mainwindow.h"
#include <QImage>
#include <QColor>
#include <QImageReader>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pImageLabel(new QLabel),
      pImageFilePath(new QLineEdit), pSelectFile(new QPushButton),
      pImageReader(new QImageReader),pImageList(new QListWidget)
{
    QGridLayout *layout = new QGridLayout;

    layout->addWidget(pImageLabel,0,0,1,2);

    QFormLayout *formlayout = new QFormLayout;
    pSelectFile->setText("选择图片文件");
    pImageFilePath->setReadOnly(true);
    QSizePolicy sizePolicy = pImageFilePath->sizePolicy();
    sizePolicy.setHorizontalStretch(1);
    pImageFilePath->setSizePolicy(sizePolicy);
    formlayout->addRow(pImageFilePath,pSelectFile);
    layout->addLayout(formlayout, 1,0,1,2);
    connect(pSelectFile, SIGNAL(clicked()), this, SLOT(onSelectFileButtonClicked()));

    pImageList->setSpacing(20);
    pImageList->setViewMode(QListView::IconMode);
    layout->addWidget(pImageList,2,0,1,2);



    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onSelectFileButtonClicked()
{
    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::FileMode::AnyFile);
    fileDialog.setOption(QFileDialog::Option::DontUseNativeDialog);
    fileDialog.setViewMode(QFileDialog::ViewMode::Detail);
    QList<QByteArray> imageFormats = QImageReader::supportedImageFormats();
    QStringList supportFormats;
    foreach (QByteArray format, imageFormats) {
        QString imgFormat ="*.";
        imgFormat += format;
        supportFormats<<imgFormat;
    }
    fileDialog.setNameFilters(supportFormats);


    QList<QByteArray> mimeTypes = QImageReader::supportedMimeTypes();
    QStringList supportMimeTypes;
    foreach (QByteArray mimeType, mimeTypes) {
        QString imgMimeType ="";
        imgMimeType += mimeType;
        supportMimeTypes<<imgMimeType;
    }
    fileDialog.setMimeTypeFilters(supportMimeTypes);


    if(fileDialog.exec() == QDialog::Accepted)
    {
        QString file = fileDialog.selectedFiles()[0];
        pImageFilePath->setText(file);
    }
    else
    {
        return;
    }

    pImageReader->setFileName( pImageFilePath->text());

    QString imgInfo ="";

    QStringList keys = pImageReader->textKeys();
    foreach (QString key, keys) {
        imgInfo += QString("%1 :%2\n").arg(key).arg(pImageReader->text(key));
    }

    imgInfo += "format: " + pImageReader->format();
    imgInfo += "\n";

    imgInfo += QString("gamma: %1\n").arg(pImageReader->gamma());

    pImageLabel->setText(imgInfo);

    int count = pImageReader->imageCount();
    pImageList->clear();
    for (int i = 0; i <= count; i++)
    {
        pImageReader->jumpToImage(i);
        if(pImageReader->canRead())
        {
            QListWidgetItem *item = new QListWidgetItem(pImageList);
            QImage image = pImageReader->read();
            int w = image.width();
            int h = image.height();
            QPixmap targetImg = QPixmap::fromImage(image).scaled(QSize(w,h));
            item->setIcon(QIcon(targetImg));
            item->setText(QString("%1").arg(i));


        }
    }

}

