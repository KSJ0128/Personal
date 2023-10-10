#include "Student.h"

class StudentStack
{
    private:
    int top;
    Student data[MAX_SIZE];

    public:
    StudentStack()
    {
        top = -1;
    }

    void push(Student s)
    {
        if(isFull())
            printf("학생 명부가 가득 찬 상태입니다.");
        else 
            data[++top] = s;
    }

    Student pop()
    {
        if(isEmpty())
            printf("학생 명부가 빈 상태입니다.");
        else
            return data[top--];
    }

    Student peek()
    {
        if(isEmpty())
            printf("학생 명부가 빈 상태입니다.");
        else
            return data[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE-1;
    }

    void display()
    {
        for(int i = 0; i <= top; i++)
        {
            data[i].display();
        }
    }
};