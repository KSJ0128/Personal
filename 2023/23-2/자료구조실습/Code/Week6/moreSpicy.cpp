#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, scoville, cnt = 0;
    priority_queue< int, vector<int>, greater<int> >pq;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> scoville;
        pq.push(scoville);
    }

    cin >> K;
    while (pq.top() < K)
    {
        if (pq.size() < 2)
            break;
        scoville = pq.top();
        pq.pop();
        scoville += pq.top() * 2;
        pq.pop();
        pq.push(scoville);
        cnt++;
    }
    if (pq.top() >= K)
        cout << cnt;
    else
        cout << -1;
}