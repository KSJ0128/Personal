#include "9_2.h"

Fan::Fan()
{
    speed = 1;
    radius = 5;
    on = false;
}

Fan::Fan(int newSpeed, double newRadius, bool newOn)
{
    speed = newSpeed;
    radius = newRadius;
    on = newOn;
}

int Fan::getSpeed()
{
    return speed;
}

double Fan::getRadius()
{
    return radius;
}

bool Fan::getOn()
{
    return on;
}

void Fan::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

void Fan::setRadius(double newRadius)
{
    radius = newRadius;
}

void Fan::setOn(bool newOn)
{
    on = newOn;
}