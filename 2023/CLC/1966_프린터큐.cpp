// 우선 순위 큐
#include <iostream>
#include <queue>
using namespace std;
const int SIZE = 100;

int main()
{
    // 입출력 속도 빠르게 해주는 설정
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    queue<int> que;
    int T, N, M, num, value;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        int count = 1, big = 0, container[SIZE];
        cin >> N >> M;

        for(int j = 0; j < N; j++) // 큐 세팅
        {
            cin >> num;

            if(j == M) // 알고자 하는 문서의 순서
            {
                que.push(-1);
                value = num;
            }
            else
                que.push(num);

            container[j] = num;
        }

        for(int k = 0; k < N; k++) // 문서 M보다 중요도 큰 문서의 개수
        {
            if(container[k] > value)
                big++;
        }

        while(true)
        {
            if(que.front() >= value) // 중요도 크거나 같은 문서
            {
                if(que.front() > value) // 중요도 높은 문서 -1
                    big--;

                que.pop();
                count++;
            }
            else if(que.front() < value) // 중요도 낮은 문서 뒤로 옮기기
            {
                que.push(que.front());
                que.pop();
            }
            else if(que.front() == -1)
            {
                if(big == 0)
                    break;
                else
                {
                    que.push(que.front());
                    que.pop();
                }
            }
        }
        cout << count << '\n';
    }
}