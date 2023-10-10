#include <iostream>
using namespace std;
int main()
{
    int N, M, tmp, basket[100] = {0,}, i, j;
    cin >> N >> M;

    for(int a = 0; a < N; a++) // 바구니 초기화
    {
        basket[a] = a+1;
    } 

    for(int a = 0; a < M; a++)
    {
        cin >> i >> j;
        for(int f = i-1, b = j-1; f < b; f++, b--)
        {
            tmp = basket[f];
            basket[f] = basket[b];
            basket[b] = tmp;
        }
    }   

    for(int i = 0; i < N; i++)
    {
        cout << basket[i] << endl;
    }
}