#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QFileDialog;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void onFilesSelected(const QStringList& fileList);
private:
    QFileDialog *pFileDialog;
};
#endif // WIDGET_H
