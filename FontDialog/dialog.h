#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
class QFontDialog;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QFontDialog *pFontDialog;
};
#endif // DIALOG_H
