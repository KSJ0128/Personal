#include <iostream>
#include "11_12.h"
#include "11_12.cpp"
using namespace std;

int main()
{
    MyDate date1;
    MyDate date2(3435555513);

    cout << date1.getYear() << " " << date1.getMonth() << " " << date1.getDay() << endl;
    cout << date2.getYear() << " " << date2.getMonth() << " " << date2.getDay();
}