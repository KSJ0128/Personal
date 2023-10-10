#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string nStr[10000];
    string mStr[10000];
    int N, M, cnt = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> nStr[i];
    for(int j = 0; j < M; j++)
        cin >> mStr[j];
    sort(nStr, nStr+N);
    sort(mStr, mStr+M);

    for(int k = 0; k < M; k++)
    {
        if(binary_search(nStr, nStr + N, mStr[k]))
            cnt++;
    }
    cout << cnt;
}