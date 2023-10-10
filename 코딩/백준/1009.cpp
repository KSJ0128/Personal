#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T, a, b;
    cin >> T;

    int data[T];

    for(int i = 0; i < T; i++)
    {
        cin >> a >> b;
        
        if(a%10==0)
            data[i] = 10;
        else if(a%10==1)
            data[i] = 1;
        else if(a%10==2)
        {
            if(b%4==1)
                data[i] = 2;
            else if(b%4==2)
                data[i] = 4;
            else if(b%4==3)
                data[i] = 8;
            else
                data[i] = 6;
        }
        else if(a%10==3)
        {
            if(b%4==1)
                data[i] = 3;
            else if(b%4==2)
                data[i] = 9;
            else if(b%4==3)
                data[i] = 7;
            else
                data[i] = 1;
        }
        else if(a%10==4)
        {
            if(b%2==1)
                data[i] = 4;
            else 
                data[i] = 6;
        }
        else if(a%10==5)
            data[i] = 5;
        else if(a%10==6)
            data[i] = 6;
        else if(a%10==7)
        {
            if(b%4==1)
                data[i] = 7;
            else if(b%4==2)
                data[i] = 9;
            else if(b%4==3)
                data[i] = 3;
            else
                data[i] = 1;
        }
        else if(a%10==8)
        {
            if(b%4==1)
                data[i] = 8;
            else if(b%4==2)
                data[i] = 4;
            else if(b%4==3)
                data[i] = 2;
            else
                data[i] = 6;
        }
        else 
        {
            if(b%2==1)
                data[i] = 9;
            else 
                data[i] = 1;
        }
    }

    for(int j = 0; j < T; j++)
    {
        cout << data[j] << '\n';
    }
}