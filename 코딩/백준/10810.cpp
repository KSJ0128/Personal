#include <iostream>
using namespace std;
int main()
{
    int N, M, basket[100] = {0,}, i, j, k; // 초기화 문제 때문에 오답이 발생할 수 있음
    cin >> N >> M;

    for(int a = 0; a < M; a++) // M번 공 넣음
    {
        cin >> i >> j >> k;

        for(int b = i-1; b <= j-1; b++) // i 바구니부터 j 바구니까지 k공 넣음
        {
            basket[b] = k;
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << basket[i] << endl;
    }
}