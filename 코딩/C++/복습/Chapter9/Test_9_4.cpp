#include <iostream>
#include "9_4.h"
#include "9_4.cpp"
using namespace std;

int main()
{
    MyPoint myPoint1;
    MyPoint myPoint2(10,30.5);

    cout << myPoint2.distance(myPoint1.getX(), myPoint1.getY());
}