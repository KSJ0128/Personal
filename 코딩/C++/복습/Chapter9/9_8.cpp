#include "9_8.h"
#include <ctime>

Date::Date(int newYear, int newMonth, int newDay)
{
    year = newYear;
    month = newMonth;
    day = newDay;
}

// 경과 시간을 초로 나타냄
Date::Date(int elapseTime)
{
    setDate(elapseTime);
}

// 현재 날짜 생성
Date::Date()
{
    // time(0) : 현재 시간을 초로 나타낸 것
    setDate(time(0));
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setDate(int elapseTime)
{
    long seconds = elapseTime;
    long minutes = seconds / 60;
    long hours = minutes / 60;
    day = hours / 24;

    year = 1970;

    // 연도 설정
    while(day >= (isLeapYear(year) ? 366 : 365))
    {
        day -= (isLeapYear(year)) ? 366 : 365;
        year++;
    }

    month = 1;

    // 달 설정
    while(day >= getNumberOfDaysInMonth(year, month))
    {
        day -= getNumberOfDaysInMonth(year, month);
        month++;
    }
}

bool Date::isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int Date::getNumberOfDaysInMonth(int year, int month)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || 
        month == 8 || month == 10 || month == 12)
        return 31;
    
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return isLeapYear(year) ? 29 : 28;
}