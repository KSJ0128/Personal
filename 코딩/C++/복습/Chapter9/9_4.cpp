#include "9_4.h"
#include <cmath>

MyPoint::MyPoint()
{
    x = 0;
    y = 0;
}

MyPoint::MyPoint(double newX, double newY)
{
    x = newX;
    y = newY;
}

double MyPoint::getX()
{
    return x;
}

double MyPoint::getY()
{
    return y;
}

double MyPoint::distance(double otherX, double otherY)
{
    double distance = sqrt((pow(x-otherX,2))+(pow(y-otherY,2)));
    
    return distance;
}
