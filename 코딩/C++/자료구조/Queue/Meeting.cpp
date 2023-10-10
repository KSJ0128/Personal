#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

class Boy
{
    private:
    int front;
    int rear;
    string queue[MAX_SIZE];

    public:
    Boy()
    {
        front = rear = 0;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    void addFront(string s)
    {
        queue[front] = s;
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    void addRear(string s)
    {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = s;
    }

    string dequeue() // 매칭
    {
        front = (front + 1) % MAX_SIZE;
        return queue[front];
    }
};

class Girl
{
    private:
    int front;
    int rear;
    string queue[MAX_SIZE];

    public:
    Girl()
    {
        front = rear = 0;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    void addFront(string s)
    {
        queue[front] = s;
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    void addRear(string s)
    {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = s;
    }

    string dequeue() // 매칭
    {
        front = (front + 1) % MAX_SIZE;
        return queue[front];
    }
};

int main()
{
    int number = 10;
    string name;
    string gender;
    string now;
    Girl girl;
    Boy boy;

    for(int i = 0; i < 10; i++)
    {
        if(i == 0)
            cout << "미팅 주선 프로그램입니다." << endl;

        cout << "고객 이름: ";
        cin >> name;
        cout << "성별: ";
        cin >> gender;
        cout << "즉시 매칭을 원하시나요? ";
        cin >> now;

        if(gender == "m") // 남자일 때
        {
            if(now == "Y") // 즉시 매칭을 원하는 경우
                boy.addFront(name);
            else if(now == "N") // 즉시 매칭을 원하지 않는 경우
                boy.addRear(name);
            
            if(girl.isEmpty()) 
                cout << "아직 대상자가 없습니다. 기다려주십시오." << endl << endl;
            else
                cout << "커플이 탄생했습니다! " << boy.dequeue() << "과 " << girl.dequeue() << endl << endl;
        }
        else if(gender == "f") // 여자일 때
        {
            if(now == "Y") // 즉시 매칭을 원하는 경우
                girl.addFront(name);
            else if(now == "N") // 즉시 매칭을 원하지 않는 경우
                girl.addRear(name);
            
            if(boy.isEmpty())
                cout << "아직 대상자가 없습니다. 기다려주십시오." << endl << endl;
            else
                cout << "커플이 탄생했습니다! " << boy.dequeue() << "과 " << girl.dequeue() << endl << endl;
        }
    }
}