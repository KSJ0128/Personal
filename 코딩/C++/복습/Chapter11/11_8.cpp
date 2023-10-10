#include "11_8.h"
#include <math.h>
const double PI = 3.14;

Circle2D::Circle2D()
{
    this->x = 0;
    this->y = 0;  
    this->radius = 1;
}

Circle2D::Circle2D(double newX, double newY, double newRadius)
{
    this->x = newX;
    this->y = newY;
    this->radius = newRadius;
}

double Circle2D::getX() const
{
    return x;
}

double Circle2D::getY() const
{
    return y;
}

double Circle2D::getRadius() const
{
    return radius;
}

double Circle2D::getArea() const
{
    double area = radius * radius * PI;
    
    return area;
}

double Circle2D::getPerimeter() const
{
    double perimeter = 2 * radius * PI;

    return perimeter;
}

bool Circle2D::contains(double x, double y) const
{
    double distance = sqrt((pow(this->x - x,2) + pow(this->y - y, 2)));
    if(distance < radius)
        return true;
    else
        return false;
}

bool Circle2D::contains(const Circle2D& circle) const
{
    double distance = sqrt((pow(x - circle.getX(),2) + pow(y - circle.getY(), 2)));
    if(distance < radius)
        return true;
    else
        return false;
}

bool Circle2D::overlaps(const Circle2D& circle) const
{
    double distance = sqrt((pow(x - circle.getX(),2) + pow(y - circle.getY(), 2)));
    if(distance > radius)
    {
        if(radius + circle.radius > distance)
            return true;
        else
            return false;
    }
    return false;   
}