#include "widget.h"
#include <QWizard>
#include <QWizardPage>
#include <QFormLayout>
#include <QCheckBox>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QGroupBox>
#include <QSizePolicy>
#include <QDebug>
#include <QMetaObject>

Widget::Widget(QWidget *parent)
    : QWidget(parent), pWizard(new QWizard)
{
    QWizardPage* languageSetup = new QWizardPage;
    languageSetup->setTitle("Class Information");

    QString subtitle = "Specify basic about the class for which you want to generate skeleton source code files.";
    languageSetup->setSubTitle(subtitle);
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    QFormLayout *formLayout = new QFormLayout;
    QLabel *className = new QLabel("&Class name:");
    QLineEdit *classNameLineEdit = new QLineEdit;
    className->setBuddy(classNameLineEdit);
    QLabel *baseClass = new QLabel("B&ase class:");
    QLineEdit *baseClassLineEdit = new QLineEdit;
    baseClass->setBuddy(baseClassLineEdit);
    formLayout->addRow(className,classNameLineEdit);
    formLayout->addRow(baseClass, baseClassLineEdit);

    QCheckBox *generateMacro = new QCheckBox("Generate Q_OBJECT &macro");

    QVBoxLayout *constructorGroupLayout = new QVBoxLayout;
    QGroupBox *constructorGroupBox = new QGroupBox;
    constructorGroupBox->setTitle("C&onstructor");

    QButtonGroup *constructorButtonBox = new QButtonGroup;
    QRadioButton *objectStyle = new QRadioButton("&QObjecst-style constructor");
    QRadioButton *widgetStyle = new QRadioButton("Q&Widget-style constructor");
    QRadioButton *defaultStyle = new QRadioButton("&Default constructor");
    defaultStyle->setChecked(true);
    constructorButtonBox->addButton(objectStyle,0);
    constructorButtonBox->addButton(widgetStyle,1);
    constructorButtonBox->addButton(defaultStyle,2);
    constructorButtonBox->setExclusive(true);

    QCheckBox *copyConstructor = new QCheckBox("&Generate copy constructor and operator=");

    constructorGroupLayout->addWidget(objectStyle);
    constructorGroupLayout->addWidget(widgetStyle);
    constructorGroupLayout->addWidget(defaultStyle);
    constructorGroupLayout->addWidget(copyConstructor);
    constructorGroupBox->setLayout(constructorGroupLayout);
    constructorGroupBox->setFlat(true);



    vBoxLayout->addLayout(formLayout);
    vBoxLayout->addWidget(generateMacro);
    vBoxLayout->addWidget(constructorGroupBox);

    languageSetup->setLayout(vBoxLayout);
    QSizePolicy policy = languageSetup->sizePolicy();
    policy.setHorizontalPolicy(QSizePolicy::Expanding);
    policy.setVerticalPolicy(QSizePolicy::Expanding);
    languageSetup->setSizePolicy(policy);



    QWizardPage *dispaly = new QWizardPage;
    QVBoxLayout *displayLayout = new QVBoxLayout;
    dispaly->setTitle("Display");
    dispaly->setSubTitle("show user selection");
    QLabel *displayContent = new QLabel;
    displayLayout->addWidget(displayContent);
    dispaly->setLayout(displayLayout);

    pWizard->addPage(languageSetup);
    pWizard->addPage(dispaly);
    pWizard->setWindowTitle("Class Wizard");
    connect(pWizard, SIGNAL(currentIdChanged(int)), this, SLOT(onCurrentIdChanged(int)));
    pWizard->show();
}

Widget::~Widget()
{
}

void Widget::onCurrentIdChanged(int index)
{
    qDebug()<<__func__<<": index " << index;
    QWizardPage *firstPage;
    if(index==1)
    {
        firstPage = pWizard->page(index-1);
        QList<QLineEdit*> list = firstPage->findChildren<QLineEdit*>();
        QString str = "";
        foreach (QLineEdit* lineEdit, list) {
            str += lineEdit->text();
            str += "\n";
        }
        QWizardPage *currentPage = pWizard->currentPage();
        QLabel* label = currentPage->findChild<QLabel*>();
        label->setText(str);




    }
}

