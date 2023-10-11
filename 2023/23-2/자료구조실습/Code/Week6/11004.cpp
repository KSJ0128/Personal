#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K, A;
    priority_queue< int, vector<int>, greater<int> > pq;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> A;
        pq.push(A);
    }

    for (int j = 0; j < K-1; j++)
        pq.pop();
    cout << pq.top();
}