#include <iostream>
#include <queue>
using namespace std;
#define MAX_QUEUE 100

class CircularQueue 
{
    public:
	int arr[MAX_QUEUE];
	int front = 0, rear = 0;

	int getFront() 
    { 
        return arr[front]; 
    }
	bool isEmpty() 
    { 
        return (front == rear); 
    }
	bool isFull() 
    { 
        return ((rear + 1) % MAX_QUEUE == front); 
    }
	int size() 
    { 
        return (front > rear ? front - rear : rear - front); 
    }
	void enqueue(int element) 
	{ 
		if (isFull()) 
            cout << "Queue is FULL!\n";
		else 
		{
			arr[rear] = element;
			rear = (rear + 1) % MAX_QUEUE;
		}
	}
	void dequeue() 
	{
		if (isEmpty()) 
            cout << "Queue is Empty!\n";
		else 
            front = (front + 1) % MAX_QUEUE;
	}
};

int main()
{
    CircularQueue que;
    queue<int> NK;
    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++)
        que.enqueue(i);
    
    while(que.size() >= 2)
    {
        for(int j = 0; j < K-1; j++)
        {
            que.enqueue(que.getFront());
            que.dequeue();
        }
        NK.push(que.getFront());
        que.dequeue();
        NK.push(que.getFront());
        que.dequeue();
    }

    while(!NK.empty())
    {
        if(NK.size() == 1)
            cout << NK.front();
        else
            cout << NK.front() << " ";
        NK.pop();
    }
}

