#include <iostream>
using namespace std;

int gcm(int n1, int n2)
{
    int g;
    
    if(n2 % n1 == 0) // 배수 관계
    {
        g = n1;
    }
    else // 배수 관계 아닐 때
    {
        for(int i = 1; i <= n1; i++)
        {
            if((n1 % i == 0) && (n2 % i == 0))
            {   
                g = i;
            }
        }
    }

    return g;
}

int lcm(int n1, int n2)
{
    int l;

    if(n2 % n1 == 0) // 배수 관계
    {
        l = n2;
    }
    else
    {
        for(int i = 1; i <= n1; i++)
        {
            if((n2 * i) % n1 == 0) // n2의 배수이면서 n1의 배수일 때
            {
                l = n2 * i;
                break;
            }
        }
    }

    return l;
}

int main()
{
    int n1, n2, n3;
    
    cin >> n1 >> n2;

    if(n1>n2) // n1이 n2보다 작게
    {
        n3 = n2;
        n2= n1;
        n1 = n3;
    }

    cout << gcm(n1,n2) << endl << lcm(n1,n2);
}