#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

class CircularQueue // 원형 큐
{
    private:
    int front;
    int rear;
    int queue[MAX_SIZE];

    public:
    CircularQueue()
    {
        front = rear = 0;
    }
    
    void enqueue(int i)
    {
        if(!isFull())
        {
            rear = (rear+1) % MAX_SIZE; // rear = MAX_SIZE인 경우 % MAX_SIZE 통해 0으로 변환
            queue[rear] = i;
        }
        else
        {
            cout << "큐가 가득찬 상태입니다. 프로그램 종료합니다.";
            exit(0);
        }
    }

    int dequeue()
    {
        if(!isEmpty())
        {
            front = (front+1) % MAX_SIZE; // front = MAX_SIZE인 경우 % MAX_SIZE 통해 0으로 변환
            return queue[front];
        }
        else
        {
            cout << "큐가 빈 상태입니다. 프로그램 종료합니다.";
            exit(0);
        }
    }

    int peek()
    {
        return queue[(front+1) % MAX_SIZE]; // front = MAX_SIZE인 경우 % MAX_SIZE 통해 0으로 변환
    }

    void display()
    {
        int maxi = (front > rear) ? rear : rear + MAX_SIZE; 

        for(int i = front + 1; i < maxi; i++)
        {
            cout << queue[i % MAX_SIZE];
        }
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear+1) % MAX_SIZE == front;
    }
};