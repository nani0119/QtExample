#include "mainwindow.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QIcon>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pListWidget(new QListWidget)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);


    QListWidgetItem *pGCBItem = new QListWidgetItem();
    pGCBItem->setIcon(QIcon(":/img/GCB"));
    pGCBItem->setText("GCB");
    pGCBItem->setData(Qt::UserRole, "this a GCB app");
    pListWidget->addItem(pGCBItem);

    QListWidgetItem *pIm6Item = new QListWidgetItem(QIcon(":/img/Im6"),"im6");
    pIm6Item->setData(Qt::UserRole, "this a Im6 app");
    pListWidget->addItem(pIm6Item);

    QListWidgetItem *pOctaveItem = new QListWidgetItem(QIcon(":/img/Octave"),"Octave");
    pOctaveItem->setData(Qt::UserRole, "this a Octave app");
    pListWidget->addItem(pOctaveItem);

    QListWidgetItem *pPdfReaderItem = new QListWidgetItem(QIcon(":/img/PdfReader"),"PdfReader");
    pPdfReaderItem->setData(Qt::UserRole, "this a PdfReader app");
    pListWidget->addItem(pPdfReaderItem);

    QListWidgetItem *pRemminaItem = new QListWidgetItem(QIcon(":/img/Remmina"),"Remmina");
    pRemminaItem->setData(Qt::UserRole, "this a Remmina app");
    pListWidget->addItem(pRemminaItem);

    QListWidgetItem *pSmplayerItem = new QListWidgetItem(QIcon(":/img/Smplayer"),"Smplayer");
    pSmplayerItem->setData(Qt::UserRole, "this a Smplayer app");
    pListWidget->addItem(pSmplayerItem);

    QListWidgetItem *pSogouPinyinItem = new QListWidgetItem(QIcon(":/img/SogouPinyin"),"SogouPinyin");
    pSogouPinyinItem->setData(Qt::UserRole, "this a SogouPinyin app");
    pListWidget->addItem(pSogouPinyinItem);

    QListWidgetItem *pUnityColorItem = new QListWidgetItem(QIcon(":/img/UnityColor"),"UnityColor");
    pUnityColorItem->setData(Qt::UserRole, "this a UnityColor app");
    pListWidget->addItem(pUnityColorItem);

    QListWidgetItem *UnityTweakToolItem = new QListWidgetItem(QIcon(":/img/UnityTweakTool"),"UnityTweakTool");
    UnityTweakToolItem->setData(Qt::UserRole, "this a UnityTweakTool app");
    pListWidget->addItem(UnityTweakToolItem);

    layout->addWidget(pListWidget);
    connect(pListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListWidgetItemClicked(QListWidgetItem*)));
    connect(pListWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onListWidgetCurrentItemChanged(QListWidgetItem*,QListWidgetItem*)));


    QRadioButton *listStyleButton = new QRadioButton("as list");
    QRadioButton *iconStyleButton = new QRadioButton("as icon");
    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->addButton(listStyleButton);
    buttonGroup->addButton(iconStyleButton);
    buttonGroup->setExclusive(true);

    layout->addWidget(listStyleButton);
    layout->addWidget(iconStyleButton);
    listStyleButton->setChecked(true);
    onListStyleRadioButtonClicked();
    connect(listStyleButton, SIGNAL(clicked()),this,SLOT(onListStyleRadioButtonClicked()));
    connect(iconStyleButton, SIGNAL(clicked()),this,SLOT(onIconStyleRadioButtonClicked()));

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setGeometry(0,0,380,380);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onListWidgetItemClicked(QListWidgetItem* item)
{
    QString str = "";
    str += QString("row: %1\n").arg(pListWidget->currentRow());
    str += "text: " + item->text() + "\n";
    str += "date: " + item->data(Qt::UserRole).toString() + "\n";
    qDebug()<<__func__<<":"<<str;

}

void MainWindow::onListWidgetCurrentItemChanged(QListWidgetItem *current , QListWidgetItem * previous)
{
    QString str = "";
    if(previous != nullptr)
    {
        str += "previous text: " + previous->text() + "\n";
        str += "previous date: " + previous->data(Qt::UserRole).toString() + "\n";
    }
    else
    {
        str += "previous listWidgetItem nullptr";
        str += "\n";
    }
    if(current != nullptr)
    {
        str += "current text: " + current->text() + "\n";
        str += "current date: " + current->data(Qt::UserRole).toString() + "\n";
    }
    else
    {
        str += "current listWidgetItem nullptr";
        str += "\n";
    }
    pLabel->setText(str);
}

void MainWindow::onListStyleRadioButtonClicked()
{

    //pListWidget->setSpacing(0);
    pListWidget->setGridSize(QSize(128,64));
    pListWidget->setWordWrap(false);
    pListWidget->setWrapping(true);
    pListWidget->setFlow(QListView::LeftToRight);
    pListWidget->setViewMode(QListView::ListMode);

}

void MainWindow::onIconStyleRadioButtonClicked()
{
    //pListWidget->setSpacing(20);
    pListWidget->setGridSize(QSize(128,64));
    pListWidget->setWordWrap(false);
    pListWidget->setWrapping(true);
    pListWidget->setFlow(QListView::TopToBottom);
    pListWidget->setViewMode(QListView::IconMode);

}
