#ifndef LINEAR_H
#define LINEAR_H

class Linear
{
    public:
    Linear(double, double, double, double, double, double);
    double getA();
    double getB();
    double getC();
    double getD();
    double getE();
    double getF();
    bool isSolvable();
    double getX();
    double getY();

    private:
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
};

#endif