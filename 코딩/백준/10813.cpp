#include <iostream>
using namespace std;
int main()
{
    int N, M, basket[100] = {0,}, i, j, tmp = 0;
    cin >> N >> M;

    for(int a = 0; a < N; a++)
    {
        basket[a] = a+1;
    }

    for(int a = 0; a < M; a++)
    {
        cin >> i >> j;
        tmp = basket[i-1];
        basket[i-1] = basket[j-1];
        basket[j-1] = tmp;
    }

    for(int i = 0; i < N; i++)
    {
        cout << basket[i] << endl;
    }
}