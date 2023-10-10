#include <iostream>
using namespace std;

int main()
{
    int sum, b;
    cin >> sum;

    for(int i=0; i<9; i++)
    {
        cin >> b;
        sum -= b;
    }

    cout << sum;
}