#ifndef MYPOINT_H
#define MYPOINT_H

class MyPoint
{
    public:
    MyPoint();
    MyPoint(double, double);
    double getX();
    double getY();
    double distance(double, double);

    private:
    double x;
    double y;
};

#endif