#include <iostream>
using namespace std;
int main()
{
    int X, n = 1, sum = 1;
    cin >> X;

    while(1)
    {
        if(X >= sum && X < sum + n + 1)
            break;
        n++;
        sum += n;
    }
    if(X == 1)
    {
        cout << "1/1";
        return 0;
    }
    cout << X - sum << '/' << n+2 - X + sum;
}