#include <iostream>
#include "11_8.h"
#include "11_8.cpp"
using namespace std;

int main()
{
    Circle2D c1(2, 2, 2.5);
    Circle2D c2(2, 2, 5.5);
    Circle2D c3(4, 5, 10.5);

    cout << c1.getArea() << endl << c1.getPerimeter() << endl;
    cout << c1.contains(3, 3) << endl << c1.contains(c2) << endl << c1.overlaps(c3);
}