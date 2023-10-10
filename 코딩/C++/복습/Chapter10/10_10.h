#ifndef MY_INTEGER_H
#define MY_INTEGER_H
#include <string>
using namespace std;

class MyInteger
{
    public:
    MyInteger(int);
    
    const int getValue();

    const bool isEven();
    const bool isOdd();
    const bool isPrime();

    static bool isEven(int);
    static bool isOdd(int);
    static bool isPrime(int);

    static bool isEven(const MyInteger&);
    static bool isOdd(const MyInteger&);
    static bool isPrime(const MyInteger&);    

    const bool equals(int);
    const bool equals(const MyInteger&);

    const int parseInt(const string&);

    private:
    int value;
};

#endif