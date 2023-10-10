#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    double que[891];
    double boucher[891] = {0.0};

    public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(double price, int pClass)
    {
        if(pClass == 2)
            que[++rear] = price;
    }

    double dequeue()
    {
        return que[++front];
    }

    void check()
    {
        for(int i = 0; i <= rear; i++)
        {
            double price = dequeue(); // pop된 ticket price

            for(int j = front + 1; j <= rear; j++)
            {
                if(price > que[j]) // 뒤의 티켓가가 더 작은 경우 해당 티켓가 * 0.1 = 바우처
                {
                    boucher[i] = que[j] * 0.1;
                    break;
                }
            }
        }
    }

    void print()
    {
        for(int i = 0; i <= rear; i++)
        {
            cout << boucher[i] << " ";
        }
    }
};

int main()
{
    int price, pClass;
    Queue que;

    for(int i = 0; i < 5; i++)
    {
        cin >> price;
        que.enqueue(price, pClass);
    }

    que.check();
    que.print();
}

// 큐로 삽입 fairs 데이터 삽입
// 하나를 pop한다. pop한 티켓가보다 작은 티켓값의 10%가 해당 티켓의 바우처 금액
// 티켓가 비교해 뒤의 티켓가가 더 크면 index+1
// 작으면 해당 금액 * 0.1 출력
// 작은 티켓가 없으면 0 출력