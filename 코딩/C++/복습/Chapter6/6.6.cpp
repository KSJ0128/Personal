#include <iostream>
using namespace std;

void displayPattern(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j > 0; j--)
        {
            cout << j << " "
        }
        cout << endl;
    }
    
    return;
}

int main()
{
    int num;
    cin >> num;
    
    displayPattern(num);
}