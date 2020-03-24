#ifndef BOXSET_H
#define BOXSET_H

#include <QObject>
#include <QTextStream>
#include <QBoxSet>

class BoxSet : public QtCharts::QBoxSet
{
    Q_OBJECT
public:
    BoxSet(const QString label = QString(), QObject *parent = nullptr);
protected:
    QList<qreal> getExceptionData();
    void setExceptionData(QList<qreal> exceptionData);

private:
    QList<qreal> exceptionData;
};


class BoxDataReader : public QTextStream
{
public:
    explicit BoxDataReader(QIODevice *device);
    BoxSet *readBox();
    void readFile(QIODevice *device);

protected:
    qreal findMedian(int begin, int end);

private:
    QList<qreal> sortedList;
};

#endif // BOXSET_H
