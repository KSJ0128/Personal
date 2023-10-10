#include <iostream>
#include <queue>
using namespace std;
const int SIZE = 500000;

int main()
{
    queue<int> q;
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    while(q.size() != 1)
    {
        q.pop(); // 제일 위에 있는 카드를 바닥에 버린다
        q.push(q.front()); // 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다
        q.pop();
    }

    cout << q.front();
}