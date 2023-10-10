#include <iostream>
#include "10_10.h"
#include "10_10.cpp"
using namespace std;

int main()
{
    MyInteger integer1(5);
    MyInteger integer2(7);

    cout << integer1.isEven() << endl << MyInteger::isOdd(2) <<
    MyInteger::isPrime(integer2) << endl << integer1.equals(7) <<
    MyInteger::parseInt("32");
}