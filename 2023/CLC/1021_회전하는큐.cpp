#include <iostream>
#include <deque>
using namespace std;

/*
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> q;
    int n, m, target;
    int cnt = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) { //n까지의 숫자 입력
        q.push_back(i);
    }

    for (int i = 0; i < m; i++) { //m만큼 반복
        cin >> target;
        int index = 0;

        for (int i = 0; i < q.size(); i++) {
            if (q[i] == target) { //타겟의 인덱스 찾기
                index = i;
                break;
            }
        }
        if (index > q.size() - index) { //타겟이 뒷쪽에 있으면
            while (1) {
                if (q.front() == target) {
                    q.pop_front();
                    break;
                }
                q.push_front(q.back());  //3번 연산 수행
                q.pop_back();
                cnt++;
            }
        }
        else {
            while (1) {
                if (q.front() == target) {
                    q.pop_front();
                    break;
                }
                q.push_back(q.front()); //2번 연산 수행
                q.pop_front();
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
*/

/*
#include <iostream>
#include <deque>
#define MAX_SIZE 100
using namespace std;
int main()
{
    deque<int> deq;
    int n, m;
    int find[MAX_SIZE];
    int count;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        deq.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> find[i];
    }
    int indfro, indbeh;
    int t = 0;
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        indfro = 0;
        indbeh = 0;
        deque<int> d1(deq);
        deque<int> d2(deq);
        while (d1.front() != find[i])
        {
            d1.push_back(d1.front());
            d1.pop_front();
            indfro++;
        }
        while (d2.back() != find[i])
        {
            d2.push_front(d2.back());
            d2.pop_back();
            indbeh++;
        }
        if (indfro > indbeh) // 왼쪽 방향으로 가는 것이 빠른 경우
        {
            s += indbeh + 1;
            d2.pop_back();
            deq = d2;
        }
        else // 오른쪽 방향으로 가는 것이 빠른 경우
        {
            s += indfro;
            d1.pop_front();
            deq = d1;
        }
    }
    cout << s;
    return 0;
}
*/

int main()
{
    deque<int> deq;
    int N, M, num, count = 0;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) // 큐 세팅
    {
        deq.push_back(i);
    }

    for(int j = 0; j < M; j++)
    {
        cin >> num;
    }


}