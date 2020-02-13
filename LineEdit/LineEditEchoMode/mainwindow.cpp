#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QValidator>
#include <QRegExp>
#include <QFrame>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pNormalLabel(new QLabel),pNoEchoLabel(new QLabel),pPasswordLabel(new QLabel),pPasswordEchoOnEditLabel(new QLabel),
      pNormalLineEdit(new QLineEdit), pNoEchoLineEdit(new QLineEdit), pPasswordLineEdit(new QLineEdit), pPasswordEchoOnEditLineEdit(new QLineEdit)
{

    QGridLayout *gridLayout = new QGridLayout;

    pNormalLabel->setText("Normal Mode:");
    pNormalLabel->setBuddy(pNormalLineEdit);
    gridLayout->addWidget(pNormalLabel,0,0);

    QRegExp regx("[a-z]+$");
    QValidator *valiadtor = new QRegExpValidator(regx,pNormalLineEdit);
    pNormalLineEdit->setValidator(valiadtor);
    pNormalLineEdit->setPlaceholderText("Normal");
    pNormalLineEdit->setEchoMode(QLineEdit::Normal);
    //最大长度
    pNormalLineEdit->setMaxLength(10);



    gridLayout->addWidget(pNormalLineEdit,0,1);
    connect(pNormalLineEdit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(onNormalCursorPositionChanged(int, int)));
    connect(pNormalLineEdit, SIGNAL(textEdited(const QString&)), this, SLOT(onNormalTextEdited(const QString&)));
    connect(pNormalLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(onNormalTextChanged(const QString&)));
    connect(pNormalLineEdit, SIGNAL(selectionChanged()), this, SLOT(onNormalSelectionChanged()));
    connect(pNormalLineEdit, SIGNAL(returnPressed()), this, SLOT(onNormalReturnPressed()));
    connect(pNormalLineEdit, SIGNAL(editingFinished()), this, SLOT(onNormalEditingFinished()));
    connect(pNormalLineEdit, SIGNAL(inputRejected()), this, SLOT(onNormalInputRejected()));



    pNoEchoLabel->setText("NoEcho Mode:");
    pNoEchoLabel->setBuddy(pNoEchoLineEdit);
    gridLayout->addWidget(pNoEchoLabel,1,0);

    pNoEchoLineEdit->setPlaceholderText("NoEcho");
    pNoEchoLineEdit->setEchoMode(QLineEdit::NoEcho);
    gridLayout->addWidget(pNoEchoLineEdit,1,1);

    pPasswordLabel->setText("Password Mode:");
    pPasswordLabel->setBuddy(pPasswordLineEdit);
    gridLayout->addWidget(pPasswordLabel,2,0);

    pPasswordLineEdit->setPlaceholderText("Password");
    pPasswordLineEdit->setEchoMode(QLineEdit::Password);
    gridLayout->addWidget(pPasswordLineEdit,2,1);

    pPasswordEchoOnEditLabel->setText("PasswordEchoOnEdit Mode:");
    pPasswordEchoOnEditLabel->setBuddy(pPasswordEchoOnEditLineEdit);
    gridLayout->addWidget(pPasswordEchoOnEditLabel,3,0);

    pPasswordEchoOnEditLineEdit->setPlaceholderText("asswordEchoOnEdit");
    pPasswordEchoOnEditLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    gridLayout->addWidget(pPasswordEchoOnEditLineEdit,3,1);
    //=================================================================


    QFrame * line = new QFrame();

    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    gridLayout->addWidget(line, 4,0, 1, -1);


    pNormalReadOnlyLabel = new QLabel;
    pNormalReadOnlyLineEdit = new QLineEdit;
    pNormalReadOnlyLabel->setText("NormalReadOnly:");
    pNormalReadOnlyLabel->setBuddy(pNormalReadOnlyLineEdit);
    gridLayout->addWidget(pNormalReadOnlyLabel,5,0);
    pNormalReadOnlyLineEdit->setPlaceholderText("NormalReadOnly");
    //只读
    pNormalReadOnlyLineEdit->setReadOnly(true);
    gridLayout->addWidget(pNormalReadOnlyLineEdit,5,1);
    pNormalReadOnlyLineEdit->setText("ReadOnly");
    //不接受焦点即用户鼠标和键盘不能对控件进行任何操作
    pNormalReadOnlyLineEdit->setFocusPolicy(Qt::NoFocus);


    pNormalOtherLabel = new QLabel;
    pNormalOtherLineEdit= new QLineEdit;
    pNormalOtherLabel->setText("Normal Other:");
    pNormalOtherLabel->setBuddy(pNormalOtherLineEdit);
    gridLayout->addWidget(pNormalOtherLabel,6,0);
    pNormalOtherLineEdit->setText("12345678");
    //无框
    pNormalOtherLineEdit->setFrame(false);
    //pNormalOtherLineEdit->setDisabled(true);
    //设置无右键菜单
    pNormalOtherLineEdit->setContextMenuPolicy(Qt::NoContextMenu);
    pNormalOtherLineEdit->installEventFilter(this);

    gridLayout->addWidget(pNormalOtherLineEdit,6,1);


    QWidget* widget = new QWidget(this);
    widget->setLayout(gridLayout);
    setCentralWidget(widget);


}

MainWindow::~MainWindow()
{
}

void MainWindow::onNormalTextEdited(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}

void MainWindow::onNormalTextChanged(const QString &text)
{
    qDebug()<<__func__<<":"<<text;
}

void MainWindow::onNormalSelectionChanged()
{
    qDebug()<<__func__<<":"<<pNormalLineEdit->selectedText();
}

void MainWindow::onNormalReturnPressed()
{
    qDebug()<<__func__<<":"<<"Return or Enter key is pressed";
}

void MainWindow::onNormalEditingFinished()
{
    qDebug()<<__func__<<":"<<"the Return or Enter key is pressed or the line edit loses focus";
}

void MainWindow::onNormalInputRejected()
{
    qDebug()<<__func__<<":"<<"Input is Rejected";
}

void MainWindow::onNormalCursorPositionChanged(int oldPos, int newPos)
{
    qDebug()<<__func__<<":"<<"oldPos " << oldPos <<" "<<"newPos " <<newPos;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == pNormalOtherLineEdit)
    {
        if (e->type() == QEvent::KeyPress)
        {
            //pNormalOtherLineEdit禁用键盘按键
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
            qDebug()<<__func__<<":"<<"pNormalOtherLineEdit event:"<<keyEvent->key();
            return true;
        }
    }
    return QMainWindow::eventFilter(obj,e);
}
