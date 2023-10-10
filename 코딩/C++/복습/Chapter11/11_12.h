#ifndef MY_DATE
#define MY_DATE

class MyDate
{
    private:
        int year;
        int month;
        int day;

    public:
        MyDate();
        MyDate(long);
        MyDate(int, int, int);

        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void setYear(int);
        void setMonth(int);
        void setDay(int);
        void setDate(long elapsedTime);
        bool isLeapYear(int);
        int getNumbersOfMonth(int, int);
};

#endif
