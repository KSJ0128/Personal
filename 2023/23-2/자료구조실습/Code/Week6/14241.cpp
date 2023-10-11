#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, x, score = 0, s1, s2;
    priority_queue< int, vector<int>, less<int> >pq;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        pq.push(x);
    }

    s1 = pq.top();
    pq.pop();

    for (int j = 0; j < N-1; j++)
    {
        score += s1 * pq.top();
        s1 += pq.top();
        pq.pop();
    }

    cout << score;
}