#include <iostream>
using namespace std;
//true = 1, false = 0 -> 기본적으로 false로 세팅됐다 생각하기

void prime(int M, int N)
{
    bool check[1000000]; // 배열 크기 N 아니고 1000000으로 초기화해야함
    check[0] = true;
    check[1] = true;

    for(int i = 2; i <= N; i++)
    {
        if(check[i]) // 이미 제거된 경우
            continue;

        for(int j = 2*i; j <= N; j+=i)
            check[j] = true;
    }
    
    for(int l = M; l<=N; l++)
    {
        if(!check[l])
            cout << l << '\n';
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    prime(M, N);
}