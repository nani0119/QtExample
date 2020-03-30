#include "servicevaluetest.h"
#include <QDebug>

ServiceValueTest::ServiceValueTest(int value)
{
    m_value = value;
}

int ServiceValueTest::maxValue()
{
    qDebug()<<__func__<<" max val:100";
    return 100;
}

int ServiceValueTest::minValue()
{
    qDebug()<<__func__<<" min val:0";
    return 0;
}

int ServiceValueTest::value()
{
    qDebug()<<__func__<<" val:"<<m_value;
    return m_value;
}

void ServiceValueTest::setValue(int val)
{
    qDebug()<<__func__<<" set val:"<<val;
    m_value = val;
}


