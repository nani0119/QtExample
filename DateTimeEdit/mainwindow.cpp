#include "mainwindow.h"
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QDateTime>
#include <QDate>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pCurrentDateTime(new QDateTimeEdit(QDateTime::currentDateTime())),
      pDateTime(new QDateTimeEdit), pDate(new QDateTimeEdit), pTime(new QDateTimeEdit), pLabel(new QLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;
    pCurrentDateTime->setDisplayFormat("yyyy/MM/dd HH:mm:ss:zzz dddd AP");
    layout->addWidget(pCurrentDateTime);
    connect(pCurrentDateTime, SIGNAL(dateTimeChanged(const QDateTime&)), this, SLOT(onDateTimeChanged(const QDateTime&)));


    QDateTime *dateTime = new QDateTime();
    QDate date(2019,1,1);
    QTime time(1,1,1);
    dateTime->setDate(date);
    dateTime->setTime(time);


    pDateTime->setDateTime(*dateTime);
    pDateTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    pDateTime->setMaximumDate(date.addDays(365));
    pDateTime->setMinimumDate(date.addDays(-365));
    pDateTime->setCalendarPopup(true);
    layout->addWidget(pDateTime);

    pDate->setDate(QDate::currentDate());
    pDate->setDisplayFormat("yy.M.d");
    layout->addWidget(pDate);

    pTime->setTime(QTime::currentTime());
    pTime->setDisplayFormat("H:mm");
    layout->addWidget(pTime);

    layout->addWidget(pLabel);


    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onDateTimeChanged(const QDateTime &dateTime)
{
    QString str = "Changed Time: " + dateTime.toString("yyyy/MM/dd HH:mm:ss") + "\n";
    str += "Date: " + pCurrentDateTime->date().toString("yyyy-MM-dd") + "\n";
    str += "Max Date: " + pCurrentDateTime->maximumDate().toString("yyyy-MM-dd") + "\n";
    str += "Min Time: " + pCurrentDateTime->minimumTime().toString("HH:mm:ss") + "\n";
    str += "SectionCount: " + QString("%1").arg(pCurrentDateTime->sectionCount()) + "\n";

    QDateTimeEdit::Section section = pCurrentDateTime->currentSection();
    auto func = [](QDateTimeEdit::Section section)->QString {
                                                                QString str;
                                                                switch(section)
                                                                {
                                                                    case QDateTimeEdit::NoSection:
                                                                        str = "NoSection";
                                                                        break;
                                                                    case QDateTimeEdit::AmPmSection:
                                                                        str = "AmPmSection";
                                                                        break;
                                                                    case QDateTimeEdit::MSecSection:
                                                                        str = "MSecSection";
                                                                        break;
                                                                    case QDateTimeEdit::SecondSection:
                                                                        str = "SecondSection";
                                                                        break;
                                                                    case QDateTimeEdit::MinuteSection:
                                                                        str = "MinuteSection";
                                                                        break;
                                                                    case QDateTimeEdit::HourSection:
                                                                        str = "HourSection";
                                                                        break;
                                                                    case QDateTimeEdit::DaySection:
                                                                        str = "DaySection";
                                                                        break;
                                                                    case QDateTimeEdit::MonthSection:
                                                                        str = "MonthSection";
                                                                        break;
                                                                    case QDateTimeEdit::YearSection:
                                                                        str = "YearSection";
                                                                        break;

                                                                }
                                                                return str;
                                                             };

    str += "CurrentSection: " + func(section) + "\n";
    int currentSectionIndex = pCurrentDateTime->currentSectionIndex();
    str += "CurrentSection Index: " + QString("%1").arg(currentSectionIndex) + "\n";
    str += "CurrentSection Text: " + QString("%1").arg(pCurrentDateTime->sectionText(section)) + "\n";
    str += "Last Section Text: " + pCurrentDateTime->sectionText(pCurrentDateTime->sectionAt(pCurrentDateTime->sectionCount() - 1));

    pLabel->setText(str);
}

