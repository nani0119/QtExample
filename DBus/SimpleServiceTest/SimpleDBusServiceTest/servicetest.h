#ifndef SERVICETEST_H
#define SERVICETEST_H

#include <QObject>

class ServiceTest : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.example.servicetest.value")
public:
    explicit ServiceTest(int value);
public slots:
    int maxValue();
    int minValue();
    int value();
    void setValue(int val);
private:
    int m_value;

};
#endif // SERVICETEST_H
