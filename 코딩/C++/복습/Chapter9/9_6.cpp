#include "9_6.h"
#include <cmath>

QuadraticEquation::QuadraticEquation(int newA, int newB, int newC)
{
    a = newA;
    b = newB;
    c = newC;
}

int QuadraticEquation::getA()
{
    return a;
}

int QuadraticEquation::getB()
{
    return b;
}

int QuadraticEquation::getC()
{
    return c;
}

int QuadraticEquation::getDiscriminant()
{
    int result = pow(b,2) - 4 * a * c;
    
    return result;
}

double QuadraticEquation:: getRoot1(int discriminant)
{
    double d = (sqrt(discriminant) - b) / 2 * a;

    return d; 
}

double QuadraticEquation:: getRoot2(int discriminant)
{
    double d = (-1 * sqrt(discriminant) - b) / 2 * a;

    return d; 
}