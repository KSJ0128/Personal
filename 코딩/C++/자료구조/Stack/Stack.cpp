#include "stack.h"
#include <iostream>
using namespace std;

stack::stack()
{
    int top = -1;
    int array[MAX_SIZE] = {0,};
}

stack::~stack()
{}

void stack::push(int x)
{
    if(isFull())
        cout << "현재 스택은 가득 찬 상태입니다.";
    else
        array[++top] = x;
}

int stack::pop()
{   
    if(isEmpty())
        cout << "현재 스택은 빈 상태입니다.";
    else
        return array[top--];
}

bool stack::isEmpty()
{
    return top == -1;
}

int stack::peek()
{
    if(isEmpty())
        cout << "현재 스택은 빈 상태입니다.";
    else
        return array[top];
}

bool stack::isFull()
{
    return top == MAX_SIZE -1;
}

int stack::size()
{
    return top;
}

void stack::display()
{
    for(int i = 0; i <= top; i++)
    {
        cout << array[i] << endl;
    }
}