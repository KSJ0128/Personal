#include <iostream>
using namespace std;
int main()
{
    int M, N; // M: 최솟값, N: 최댓값
    cin >> M >> N;

    int sum = 0;
    int min = 10000;
    
    for(int i = 1; i*i <= N ; i++)
    {
        if(i*i >= M)
        {   
            sum += i*i;

            if (min > i*i)
            {
                min = i*i;
            }
        }    
    }

    if(sum == 0)
        cout << -1;
    else
        cout << sum << endl << min;
}