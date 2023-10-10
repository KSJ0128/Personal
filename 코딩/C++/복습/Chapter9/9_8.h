#ifndef DATE_H
#define DATE_H

class Date
{
    public:
    Date();
    Date(int, int, int);
    Date(int);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int);

    private:
    int year;
    int month;
    int day;
    bool isLeapYear(int);
    int getNumberOfDaysInMonth(int, int);
};

#endif