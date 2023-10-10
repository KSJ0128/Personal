#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 2000000;

class Queue
{
    private:
    int top;
    int rear;
    int que[MAX_SIZE];

    public:
    Queue()
    {
        top = rear = 0;
    }

    int empty()
    {
        if(top == rear)
            return 1;
        else 
            return 0;
    }

    void push(int X)
    {
        que[++rear] = X;
    }

    void pop()
    {
        if(empty() == 1)
            cout << -1 << '\n';
        else
            cout << que[++top] << '\n';
    }

    void size()
    {
        cout << rear - top << '\n';
    }

    void front()
    {
        if(empty() == 1)
            cout << -1 << '\n';
        else 
            cout << que[top+1] << '\n';
    }

    void back()
    {
        if(empty() == 1)
            cout << -1 << '\n';
        else 
            cout << que[rear] << '\n';
    }
};

int main()
{
    int N;
    cin >> N;
    string str;
    Queue q;

    for(int i = 0; i < N; i++)
    {
        getline(cin, str);

        if(str == "pop")
            q.pop();
        else if(str == "size")
            q.size();
        else if(str == "front")
            q.front();
        else if(str == "back")
            q.back();
        else if(str == "empty")
            cout << q.empty() << endl;
        else
        {
            int len = str.size();
            q.push(str[len-1]);
        }
    }   
}