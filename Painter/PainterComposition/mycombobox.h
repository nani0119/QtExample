#ifndef MYCOMBOX_H
#define MYCOMBOX_H

#include <QWidget>
#include <QComboBox>
class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MyComboBox(QWidget *parent = nullptr);

signals:

};

#endif // MYCOMBOX_H
