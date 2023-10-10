#include <iostream>
using namespace std;

int getSize(int n)
{
    int count = 1;

    while(n > 10)
    {
        n = n / 10;
        count++;
    }

    return count;
}

int main()
{
    int num;
    cin >> num;

    cout << getSize(num);
}