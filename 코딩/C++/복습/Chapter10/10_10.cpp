#include "10_10.h"
#include <string>

MyInteger::MyInteger(int newValue)
{
    this->value = newValue;
}

const int MyInteger::getValue()
{
    return value;
}

const bool MyInteger::isEven()
{
    return isEven(value);
}

const bool MyInteger::isOdd()
{  
    return isOdd(value);
}

const bool MyInteger::isPrime()
{
 return isPrime(value);
}

bool MyInteger::isEven(int i)
{
    return i % 2 == 0;
}

bool MyInteger::isOdd(int i)
{  
    return i % 2 == 1;
}

bool MyInteger::isPrime(int num)
{
    if(num == 1 || num == 2)
        return true;
    
    for(int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

bool MyInteger::isEven(const MyInteger& my)
{
    return isEven(my.getValue());
}

bool MyInteger::isOdd(const MyInteger& my)
{
    return isOdd(my.getValue());
}

bool MyInteger::isPrime(const MyInteger& my)
{
    return isPrime(my.getValue());
}

const bool MyInteger::equals(int i)
{
    return value == i;
}

const bool MyInteger::equals(const MyInteger& my)
{
    return value == my.getValue();
}

const int MyInteger::parseInt(const string& s) 
{   
    return stoi(s);
}