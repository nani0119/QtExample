#ifndef SERVICEVALUETEST_H
#define SERVICEVALUETEST_H

#include <QObject>

class ServiceValueTest : public QObject
{
    Q_OBJECT
public:
    explicit ServiceValueTest(int value);
public slots:
    int maxValue();
    int minValue();
    int value();
    void setValue(int val);
private:
    int m_value;

};
#endif // SERVICEVALUETEST_H
