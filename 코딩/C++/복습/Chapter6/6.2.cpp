#include <iostream>
using namespace std;

int sumDigits(long n)
{
    int sum = 0;
    
    while(n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    
    return sum;
}

int main()
{
    long num = 0;

    cin >> num;

    cout << sumDigits(num);
}