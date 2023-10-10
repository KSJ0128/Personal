#include <iostream>
using namespace std;
const int MAX_SIZE = 20;

class Infix
{
    private:
    int top;
    int operand[MAX_SIZE];
    char operator[MAX_SIZE];

    public:
    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE -1;
    }

    void pushOperand(char c)
    {
        if(!isFull())
            operand[++top] = c - '0';
        else
        {
            cout << "스택이 가득 찬 상태입니다. 프로그램 종료합니다.";
            exit(0);
        }
    }

    void pushOperator(char c)
    {
        
    }

    int popOperand()
    {
        if(!isEmpty())
            return operand[top--];
        else
        {
            cout << "스택이 빈 상태입니다. 프로그램 종료합니다.";
            exit(0);
        }
    }

    int allCalculate(string s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                pushOperand(s[i]);
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                pushOperator(s[i]);
        }

        return operand[top];
    }
};