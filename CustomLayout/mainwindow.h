#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>


class CustomLayout: public QLayout
{
public:
    CustomLayout(QWidget* parent = nullptr);
    ~CustomLayout();

        // QLayoutItem interface
public:
        virtual QSize sizeHint() const override;
        virtual void setGeometry(const QRect &) override;
        virtual QRect geometry() const override;

        // QLayout interface
public:
        virtual void addItem(QLayoutItem *) override;
        virtual QLayoutItem *itemAt(int index) const override;
        virtual QLayoutItem *takeAt(int index) override;
        virtual int count() const override;
private:
        QList<QLayoutItem*> list;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
