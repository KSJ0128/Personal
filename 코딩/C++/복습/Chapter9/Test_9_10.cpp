#include <iostream>
#include "9_10.h"
#include "9_10.cpp"
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    cout << "Enter the endpoints of the first line segment: ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter the endpoints of the second line segment: ";
    cin >> x3 >> y3 >> x4 >> y4;

    double a = (y1 - y2);
    double b = (-x1 + x2);
    double c = (y3 - y4);
    double d = (-x3 + x4);
    double e = -y1 * (x1 - x2) + (y1 - y2) * x1;
    double f = -y3 * (x3 - x4) + (y3 - y4) * x3;

    Linear linear(a,b,c,d,e,f);

    if(linear.isSolvable())
        cout << linear.getX() << " " << linear.getY();
    else
        cout << "The equation has no solution";

}