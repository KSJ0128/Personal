#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    priority_queue< int, vector<int>, greater<int> >pq;
    cin >> N;

    for (int i = 0; i < N*N; i++)
    {
        cin >> x;
        pq.push(x);
        if (i >= N)
            pq.pop();
    }
    cout << pq.top();
}