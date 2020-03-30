#include "servicetest.h"
#include <QDebug>

ServiceTest::ServiceTest(int value)
{
    m_value = value;
}

int ServiceTest::maxValue()
{
    qDebug()<<__func__<<" max val:100";
    return 100;
}

int ServiceTest::minValue()
{
    qDebug()<<__func__<<" min val:0";
    return 0;
}

int ServiceTest::value()
{
    qDebug()<<__func__<<" val:"<<m_value;
    return m_value;
}

void ServiceTest::setValue(int val)
{
    qDebug()<<__func__<<" set val:"<<val;
    m_value = val;
}


