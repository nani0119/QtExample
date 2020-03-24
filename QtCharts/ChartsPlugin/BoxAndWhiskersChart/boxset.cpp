#include "boxset.h"

BoxSet::BoxSet(const QString label, QObject *parent):QBoxSet(label, parent)
{

}

QList<qreal> BoxSet::getExceptionData()
{

}

void BoxSet::setExceptionData(QList<qreal> exceptionData)
{

}

BoxDataReader::BoxDataReader(QIODevice *device) :
    QTextStream(device)
{
}

void BoxDataReader::readFile(QIODevice *device)
{
    QTextStream::setDevice(device);
}

BoxSet *BoxDataReader::readBox()
{
    QString line = readLine();
    if (line.startsWith("#"))
        return nullptr;

    QStringList strList = line.split(" ", QString::SkipEmptyParts);

    sortedList.clear();
    for (int i = 1; i < strList.count(); i++)
        sortedList.append(strList.at(i).toDouble());

    std::sort(sortedList.begin(), sortedList.end());

    int count = sortedList.count();

    BoxSet *box = new BoxSet(strList.first());
    box->setValue(BoxSet::LowerExtreme, sortedList.first());
    box->setValue(BoxSet::UpperExtreme, sortedList.last());
    box->setValue(BoxSet::Median, findMedian(0, count));
    box->setValue(BoxSet::LowerQuartile, findMedian(0, count / 2));
    box->setValue(BoxSet::UpperQuartile, findMedian(count / 2 + (count % 2), count));
    //box->setExceptionData(exceptionData);

    return box;
}

qreal BoxDataReader::findMedian(int begin, int end)
{
    int count = end - begin;
    if (count % 2) {
        return sortedList.at(count / 2 + begin);
    } else {
        qreal right = sortedList.at(count / 2 + begin);
        qreal left = sortedList.at(count / 2 - 1 + begin);
        return (right + left) / 2.0;
    }
}
