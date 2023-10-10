#include "9_10.h"

Linear::Linear(double newA, double newB, double newC, double newD, double newE, double newF)
{
    a = newA;
    b = newB;
    c = newC;
    d = newD;
    e = newE;
    f = newF;
}

double Linear::getA()
{
    return a;
}

double Linear::getB()
{
    return b;
}

double Linear::getC()
{
    return c;
}

double Linear::getD()
{
    return d;
}

double Linear::getE()
{
    return e;
}

double Linear::getF()
{
    return f;
}

bool Linear::isSolvable()
{
    return a * d - b * c != 0;
}

double Linear::getX()
{
    return (e * d - b * f) / (a * d - b * c);
}

double Linear::getY()
{
    return (a * f - e * c) / (a * d - b * c);
}