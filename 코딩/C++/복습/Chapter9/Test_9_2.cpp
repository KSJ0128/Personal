#include <iostream>
#include "9_2.h"
#include "9_2.cpp"
using namespace std;

int main() 
{
    Fan fan1(3, 10, true); 
    Fan fan2(2, 5, false);

    cout << "fan1's info " << endl << fan1.getSpeed() << endl << fan1.getRadius() << endl << fan1.getOn() << endl;

    cout << "fan2's info " << endl << fan2.getSpeed() << endl << fan2.getRadius() << endl << fan2.getOn();
}