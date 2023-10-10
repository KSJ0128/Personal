#include <iostream>
using namespace std;

// 피보나치 함수 규칙 파악
int main()
{
    int T, N;
    int memoization[40] = {0,1,1,};

    for(int i = 3; i < 41; i++)
    {
        memoization[i] = memoization[i-2] + memoization[i-1];
    }

    cin >> T;

    for(int j = 0; j < T; j++)
    {
        cin >> N;
        if( N == 0)
            cout << "1 0 \n";
        else if( N == 1)
            cout << "0 1 \n";
        else
            cout << memoization[N-1] << " " << memoization[N] << '\n';
    }
}