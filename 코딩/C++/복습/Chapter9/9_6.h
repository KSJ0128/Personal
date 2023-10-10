#ifndef QUADRA_H
#define QUADRA_H

class QuadraticEquation
{
    public:
    QuadraticEquation(int, int, int);
    int getA();
    int getB();
    int getC();
    int getDiscriminant();
    double getRoot1(int);
    double getRoot2(int);

    private:
    int a;
    int b;
    int c;
};

#endif