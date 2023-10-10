#include <iostream>
#include "9_8.h"
#include "9_8.cpp"
using namespace std;

int main()
{
    Date date1;
    Date date2(555550);

    cout << date1.getYear() << " " << date1.getMonth() << " " << date1.getDay() << endl;
    cout << date2.getYear() << " " << date2.getMonth() << " " << date2.getDay() << endl;
}