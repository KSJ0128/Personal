#include <iostream>
#include "CircularQueue.cpp"
using namespace std;
const int MAX_SIZE = 100;

class CircularDeque: public CircularQueue
{
    public:
    CircularDeque()
    {}

    void addFront(int i)
    {
        if(!isFull())
        {
            cout << "큐가 가득찬 상태입니다. 프로그램 종료합니다.";
            exit(0);
        }
        else
        {
            queue[front] = i;
            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        }
    }

    int deletefront()
    {
        return dequeue();
    }

    void addRear(int i)
    {
        return enqueue(i);
    }

    int deleteRear()
    {
        if(!isEmpty())
        {
            cout << "큐가 빈 상태입니다. 프로그램 종료합니다.";
            exit(0);
        }
        else
        {
            int dr = queue[rear];
            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
            return dr;
        }
    }

    int getFront()
    {
        return queue[front];
    }

    int getRear()
    {
        return queue[rear];
    }

    void display()
    {
        int maxI = (front < rear) ? rear : rear + MAX_SIZE;
        for(int i = front + 1; i < maxI; i++)
        {
            cout << queue[i % MAX_SIZE];
        }
    }
}

int main()
{}