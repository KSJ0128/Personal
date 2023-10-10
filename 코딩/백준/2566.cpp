#include <iostream>
using namespace std;
int main()
{
    int max = 0, x = 0, y = 0, data;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> data;
            if (max < data)
            {
                x = i;
                y = j;
                max = data;
            }
        }
    }
    cout << max << endl;
    cout << x << " " << y;
}