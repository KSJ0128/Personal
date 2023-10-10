#include <iostream>
using namespace std;
const int MAX_SIZE = 20;

class Postfix
{
    private:
    int operand[MAX_SIZE];
    int top;

    public:
    Postfix()
    {
        top = -1;
    }

    void pushChar(char c)
    {
        if(!isFull())
        {
            operand[++top] = c - '0';
        }
        else
            cout << "스택이 가득 찬 상태입니다.";
    }

    void pushInt(int i)
    {
        if(!isFull())
        {
            operand[++top] = i;
        }
        else
            cout << "스택이 가득 찬 상태입니다.";
    }

    int pop()
    {
        if(!isEmpty())
            return operand[top--];
        else
        {
            cout << "스택이 빈 상태입니다.";
            exit(0);
        }
    }

    int allCalculate(string s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                pushChar(s[i]);
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                calculate(s[i]);
            }
        }

        return operand[top];
    }

    void calculate(char c)
    {
        if(!isEmpty())
        {
            int o2 = pop();
            int o1 = pop();

            if(c == '+')
            {
                pushInt(o1 + o2);
            }
            else if(c == '-')
            {
                pushInt(o1 - o2);
            }
            else if(c == '*')
            {
                pushInt(o1 * o2);
            }
            else if(c == '/')
            {
                pushInt(o1 / o2);
            }
        }
        else
        {
            cout << "스택이 빈 상태입니다.";
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE -1;
    }
};