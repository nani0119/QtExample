#include "mainwindow.h"
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pComboBox(new QComboBox)
{
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(pLabel);


    pComboBox->addItem( "北京", "京");
    pComboBox->addItem( "天津", "津");
    pComboBox->addItem( "河北", "冀");
    pComboBox->addItem( "山西", "晋");
    pComboBox->addItem( "内蒙古", "蒙");
    pComboBox->addItem( "辽宁", "辽");
    pComboBox->addItem( "吉林", "吉");
    pComboBox->addItem( "黑龙江", "黑");
    pComboBox->addItem( "上海", "沪");
    pComboBox->addItem( "江苏", "苏");
    pComboBox->addItem( "浙江", "浙");
    pComboBox->addItem( "安徽", "皖");
    pComboBox->addItem( "福建", "闽");
    pComboBox->addItem( "江西", "赣");
    pComboBox->addItem( "山东", "鲁");
    pComboBox->addItem( "河南", "豫");
    pComboBox->addItem( "湖北", "鄂");
    pComboBox->addItem( "湖南", "湘");
    pComboBox->addItem( "广东", "粤");
    pComboBox->addItem( "广西", "桂");
    pComboBox->addItem( "海南", "琼");
    pComboBox->addItem( "重庆", "渝");
    pComboBox->addItem( "四川", "川");
    pComboBox->addItem( "贵州", "黔");
    pComboBox->addItem( "云南", "滇");
    pComboBox->addItem( "西藏", "藏");
    pComboBox->addItem( "陕西", "陕");
    pComboBox->addItem( "甘肃", "甘");
    pComboBox->addItem( "青海", "青");
    pComboBox->addItem( "宁夏", "宁");
    pComboBox->addItem( "新疆", "新");
    pComboBox->addItem( "台湾", "台");
    pComboBox->addItem( "香港特别行政区", "港");
    pComboBox->addItem( "澳门", "澳");
    pComboBox->addItem( "aaaaaaaa", "aaaaaaaa");
    pComboBox->addItem( "bbbbbbbb", "bbbbbbbb");

    QStringList list;
    for(int index = 0; index < pComboBox->count(); index++)
    {
        list.append(pComboBox->itemText(index));
    }
    QLineEdit *pLineEdit = new QLineEdit;
    MyValidator *myValidator = new MyValidator(list);

    pLineEdit->setValidator(myValidator);
    pComboBox->setLineEdit(pLineEdit);
    //pComboBox->setEditable(true);


    layout->addWidget(pComboBox);
    connect(pComboBox, SIGNAL(activated(int)), this, SLOT(onActivated(int)));
    connect(pComboBox, SIGNAL(activated(const QString&)), this, SLOT(onActivated(const QString&)));
    connect(pComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentIndexChanged(int)));
    connect(pComboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(onCurrentIndexChanged(const QString&)));
    connect(pComboBox, SIGNAL(highlighted(int)), this, SLOT(onHighlighted(int)));
    connect(pComboBox, SIGNAL(highlighted(const QString&)), this, SLOT(onHighlighted(const QString&)));
    connect(pComboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onCurrentTextChanged(const QString&)));
    connect(pComboBox, SIGNAL(editTextChanged(const QString&)), this, SLOT(onEitTextChanged(const QString&)));

    pLabel->setText(QString("%1").arg(pComboBox->count()));

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onActivated(int index)
{
    qDebug()<<__func__<<":"<<index;
}

void MainWindow::onActivated(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}

void MainWindow::onCurrentIndexChanged(int index)
{
    qDebug()<<__func__<<":"<<index;
}

void MainWindow::onCurrentIndexChanged(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}

void MainWindow::onHighlighted(int index)
{
    qDebug()<<__func__<<":"<<index;
}

void MainWindow::onHighlighted(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}

void MainWindow::onCurrentTextChanged(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}

void MainWindow::onEitTextChanged(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}


MyValidator::MyValidator(QStringList stringList, QObject *parent):
    QValidator(parent),provinceList(stringList)
{
    foreach (QString str, provinceList) {
        qDebug()<<str;
    }
}

MyValidator::~MyValidator()
{

}

QValidator::State MyValidator::validate(QString &input, int &pos) const
{
    QValidator::State state = QValidator::Acceptable;
    QStringList result;
    result = provinceList.filter(input);

    if(result.count() == 0)
    {
        state = QValidator::Invalid;
    }
    else if (result.count() == 1 && provinceList.contains(input))
    {
        state =  QValidator::Acceptable;
    }
    else
    {
         state =  QValidator::Intermediate;
    }

    qDebug()<<__func__<<":" << state << " pos: " <<pos;
    return state;
}
