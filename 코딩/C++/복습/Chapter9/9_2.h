#ifndef FAN_H
#define FAN_H

class Fan
{
    public:
    Fan();
    Fan(int, double, bool);
    int getSpeed();
    double getRadius();
    bool getOn();
    void setSpeed(int);
    void setRadius(double);
    void setOn(bool);

    private:
    int speed;
    double radius;
    bool on;
};

#endif