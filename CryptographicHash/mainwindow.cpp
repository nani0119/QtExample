#include "mainwindow.h"
#include <QTabWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QCryptographicHash>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->setTabPosition(QTabWidget::TabPosition::North);

    fileHash = createFileHashTab();
    tabWidget->addTab(fileHash,"计算文件");



    strHash = createStrHashTab();
    tabWidget->addTab(strHash,"计算字符串");

    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onStrCalcButtonClicked()
{
    QLineEdit* input = strHash->findChild<QLineEdit*>("strInputLineEdit");
    QByteArray byteArray;
    byteArray.append(input->text());

    if(input->text().isEmpty())
    {
        return;
    }
    calc(strHash,byteArray);
}

void MainWindow::onFileSelectButtonClicked()
{
    QLineEdit* inputFile = fileHash->findChild<QLineEdit*>("fileInputLineEdit");

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::FileMode::AnyFile);
    if(dialog.exec() == QDialog::Accepted)
    {
        QString file = dialog.selectedFiles()[0];
        inputFile->clear();
        inputFile->setText(file);
    }

    clearLineEdit(fileHash);
}

void MainWindow::onFileCalcButtonClicked()
{
    QLineEdit* inputFile = fileHash->findChild<QLineEdit*>("fileInputLineEdit");
    inputFile->setReadOnly(true);
    QString fileName = inputFile->text();
    if(fileName.isEmpty())
    {
        inputFile->setReadOnly(false);
        return;
    }

    bool ok;
    QFile file(fileName);
    ok = file.open(QIODevice::ReadOnly);
    if(!ok)
    {
        qDebug()<<__func__<<":"<<QString("open file %1 fail").arg(fileName);
        inputFile->setReadOnly(false);
        return;
    }
    int len = file.size();
    if(len <= 0)
    {
        qDebug()<<__func__<<":"<<QString("file size %1").arg(len);
        inputFile->setReadOnly(false);
        return;
    }

    char *buf = new char[len];
    if(buf == nullptr)
    {
        qDebug()<<__func__<<":"<<QString("alloc memory: %1 fail").arg(len);
        inputFile->setReadOnly(false);
        return;
    }


    QDataStream data(&file);
    int readLen = data.readRawData(buf, len);
    if(readLen != len)
    {
        delete [] buf;
        qDebug()<<__func__<<":"<<QString("read %1 bytes, not %2 bytes").arg(readLen).arg(len);
        inputFile->setReadOnly(false);
        return;
    }
    calc(fileHash,buf,len);
    delete [] buf;
    inputFile->setReadOnly(false);
}

QWidget *MainWindow::createFileHashTab()
{
    QGridLayout *layout = new QGridLayout;

    QFormLayout *formLayout = createFormlayout();
    layout->addLayout(formLayout,0,0,1,2);

    QLineEdit *inputFile = new QLineEdit;
    inputFile->setObjectName("fileInputLineEdit");
    QSizePolicy inputSizePolicy = inputFile->sizePolicy();
    inputSizePolicy.setHorizontalStretch(1);
    inputFile->setSizePolicy(inputSizePolicy);
    layout->addWidget(inputFile, 1,0);

    QPushButton *fileSelectButton = new QPushButton("选择文件");
    fileSelectButton->setObjectName("fileSelectButton");
    connect(fileSelectButton, SIGNAL(clicked()),this, SLOT(onFileSelectButtonClicked()));
    layout->addWidget(fileSelectButton,1,1);

    QPushButton *calcButton = new QPushButton("计算");
    connect(calcButton, SIGNAL(clicked()),this, SLOT(onFileCalcButtonClicked()));
    layout->addWidget(calcButton,2,0,1,2);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    return widget;
}

QWidget *MainWindow::createStrHashTab()
{

    QGridLayout *layout = new QGridLayout;

    QFormLayout *formLayout = createFormlayout();
    layout->addLayout(formLayout,0,0,1,2);

    QLineEdit *input = new QLineEdit;
    input->setObjectName("strInputLineEdit");
    QSizePolicy inputSizePolicy = input->sizePolicy();
    inputSizePolicy.setHorizontalStretch(1);
    input->setSizePolicy(inputSizePolicy);

    layout->addWidget(input,1,0);

    QPushButton *calcButton = new QPushButton("计算");
    calcButton->setObjectName("strCalcButton");
    connect(calcButton, SIGNAL(clicked()),this, SLOT(onStrCalcButtonClicked()));
    layout->addWidget(calcButton,1,1);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    return widget;
}

QFormLayout *MainWindow::createFormlayout()
{
    QFormLayout *formLayout = new QFormLayout;

    QCheckBox *md5CheckBox = new QCheckBox("Md5");
    md5CheckBox->setObjectName("Md5Checkbox");
    md5CheckBox->setChecked(true);
    QLineEdit *md5LineEdit = new QLineEdit;
    md5LineEdit->setObjectName("Md5LineEdit");
    md5LineEdit->setReadOnly(true);
    QSizePolicy lineEditSizePolicy = md5LineEdit->sizePolicy();
    lineEditSizePolicy.setHorizontalStretch(1);
    lineEditSizePolicy.setVerticalStretch(1);
    md5LineEdit->setSizePolicy(lineEditSizePolicy);
    formLayout->addRow(md5CheckBox,md5LineEdit);

    QCheckBox *sha256CheckBox = new QCheckBox("Sha256");
    sha256CheckBox->setObjectName("Sha256Checkbox");
    sha256CheckBox->setChecked(true);
    QLineEdit *sha256LineEdit = new QLineEdit;
    sha256LineEdit->setObjectName("Sha256LineEdit");
    sha256LineEdit->setReadOnly(true);
    QSizePolicy sha256LineEditSizePolicy = sha256LineEdit->sizePolicy();
    sha256LineEditSizePolicy.setHorizontalStretch(1);
    sha256LineEditSizePolicy.setVerticalStretch(1);
    sha256LineEdit->setSizePolicy(sha256LineEditSizePolicy);
    formLayout->addRow(sha256CheckBox,sha256LineEdit);

    QCheckBox *sha512CheckBox = new QCheckBox("Sha512");
    sha512CheckBox->setObjectName("Sha512Checkbox");
    sha512CheckBox->setChecked(true);
    QLineEdit *sha512LineEdit = new QLineEdit;
    sha512LineEdit->setObjectName("Sha512LineEdit");
    sha512LineEdit->setReadOnly(true);
    QSizePolicy sha512LineEditSizePolicy = sha512LineEdit->sizePolicy();
    sha512LineEditSizePolicy.setHorizontalStretch(1);
    sha512LineEditSizePolicy.setVerticalStretch(1);
    sha512LineEdit->setSizePolicy(sha512LineEditSizePolicy);
    formLayout->addRow(sha512CheckBox,sha512LineEdit);

    return formLayout;
}

void MainWindow::clearLineEdit(QWidget* widget)
{
    QLineEdit* md5LineEdit = widget->findChild<QLineEdit*>("Md5LineEdit");
    md5LineEdit->clear();
    QLineEdit* sha256LineEdit = widget->findChild<QLineEdit*>("Sha256LineEdit");
    sha256LineEdit->clear();
    QLineEdit* sha512LineEdit = widget->findChild<QLineEdit*>("Sha512LineEdit");
    sha512LineEdit->clear();
}

void MainWindow::calc(QWidget* widget, const char *buf, int len)
{
    QCheckBox* md5Checkbox = widget->findChild<QCheckBox*>("Md5Checkbox");
    if(md5Checkbox->isChecked())
    {
        QCryptographicHash crypto(QCryptographicHash::Md5);
        crypto.addData(buf, len);
        QByteArray  result =crypto.result();
        QLineEdit* md5LineEdit = widget->findChild<QLineEdit*>("Md5LineEdit");
        md5LineEdit->clear();
        md5LineEdit->setText(result.toHex());
    }


    QCheckBox* sha256CheckBox = widget->findChild<QCheckBox*>("Sha256Checkbox");
    if(sha256CheckBox->isChecked())
    {
        QCryptographicHash crypto(QCryptographicHash::Sha256);
        crypto.addData(buf, len);
        QByteArray  result =crypto.result();
        QLineEdit* sha256LineEdit = widget->findChild<QLineEdit*>("Sha256LineEdit");
        sha256LineEdit->clear();
        sha256LineEdit->setText(result.toHex());
    }

    QCheckBox* sha512CheckBox = widget->findChild<QCheckBox*>("Sha512Checkbox");
    if(sha512CheckBox->isChecked())
    {
        QCryptographicHash crypto(QCryptographicHash::Sha512);
        crypto.addData(buf, len);
        QByteArray  result =crypto.result();
        QLineEdit* sha512LineEdit = widget->findChild<QLineEdit*>("Sha512LineEdit");
        sha512LineEdit->clear();
        sha512LineEdit->setText(result.toHex());
    }
}

void MainWindow::calc(QWidget* widget, QByteArray &byteArray)
{
    const char *buf = byteArray.data();
    int len = byteArray.length();
    calc(widget,buf,len);
}
