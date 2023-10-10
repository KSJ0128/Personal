#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int x[N], y[N], rank[N];

    for(int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < N; i++)
    {
        rank[i] = 1;
        for(int j = 0; j < N; j++)
        {
            if(i == j)
                continue;
            
            if(x[i] < x[j] && y[i] < y[j])
                rank[i]++;
        }
        cout << rank[i] << '\n';
    }
}