#include <iostream>
#include "9_6.h"
#include "9_6.cpp"
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    QuadraticEquation quadra(a, b, c);

    int d = quadra.getDiscriminant();
    
    if(d > 0)
        cout << quadra.getRoot1(d) << endl << quadra.getRoot2(d);
    else if(d == 0)
        cout << quadra.getRoot1(d);
    else
        cout << "The Equation has no real roots";

}