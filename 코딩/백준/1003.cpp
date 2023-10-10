#include <iostream>
using namespace std;

//메모이제이션 활용, 시간초과
int fibonacci(int n, int& zero, int& one) 
{
    int memoization[40] = {0, 1,};
    
    if (memoization[n] > 0) 
        return memoization[n];
    else 
        return memoization[n] = fibonacci(n-1, zero, one) + fibonacci(n-2, zero, one);

    if(n == 0)
    {
        zero++;
        return memoization[0];
    }    
    else if( n == 1 )
    {
        one++;            
        return memoization[1];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int T, n, zero, one;
    cin >> T;

    for( int i = 0; i < T; i++)
    {
        cin >> n;
        fibonacci(n, zero, one);
        cout<< zero << " " << one << '\n';
        zero = 0;
        one = 0;
    }
}