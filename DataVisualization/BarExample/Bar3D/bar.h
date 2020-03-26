#ifndef BAR_H
#define BAR_H

#include <QWidget>
#include "graphmodifier.h"
class QComboBox;
class Bar : public QWidget
{
    Q_OBJECT
public:
    explicit Bar(QWidget *parent = nullptr);

private slots:
    void onDataSourceChanged(int index);
private:
    bool loadDataSource();
    QComboBox* dataSource;
    GraphModifier *modifier;
    QComboBox *rangeList;
    IBarDataInterface* barDataSource;

};

#endif // BAR_H
