#include "11_12.h"
#include <ctime>

MyDate::MyDate()
{
    setDate(time(0));
}

MyDate::MyDate(long elapsedTime)
{
    setDate(elapsedTime);
}

MyDate::MyDate(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

int MyDate::getYear() const
{
    return year;
}

int MyDate::getMonth() const
{
    return month;
}

int MyDate::getDay() const
{
    return day;
}

void MyDate::setYear(int year)
{
    this->year = year;
}

void MyDate::setMonth(int month)
{
    this->month = month;
}

void MyDate::setDay(int day)
{
    this->day = day;
}

void MyDate::setDate(long elapsedTime)
{
    long seconds = elapsedTime;
    long minutes = elapsedTime / 60;
    long hours = minutes / 60;
    day = hours / 24;
    year = 1970;
    month = 1;

    // 연도 계산
    while(day >= (isLeapYear(year)? 366 : 365))
    {
        year++;
        day -= isLeapYear(year)? 366 : 365;
    }

    // 달 계산
    while(day >= getNumbersOfMonth(year, month))
    {
        month++;
        day -= getNumbersOfMonth(year, month);
    }
}

bool MyDate::isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int MyDate::getNumbersOfMonth(int year, int month)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || 
    month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
    {
        return isLeapYear(year) ? 29 : 28;
    }
}