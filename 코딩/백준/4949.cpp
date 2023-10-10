#include <iostream>
using namespace std;

class bracket
{
    private:
        int top;
        char stack[100];
    
    public:
        bracket()
        {
            top = 0;
        }

        bool isEmpty()
        {
            return top == 0;
        }

        void push(char c)
        {
            stack[++top] = c;
        }

        char pop()
        {
            return stack[top--];
        }

        char peek()
        {
            return stack[top];
        }

        void clear()
        {
            top = 0;
        }

        void checkS()
        {
            if(peek() == '(')
                pop();
            else    
            {
                cout << "no" << endl;
                break;
            }
                
        }

        void checkB()
        {
            if(peek() == '[')
                pop();
            else    
            {
                cout << "no" << endl;
                break;
            }
        }
}

int main()
{   
    string str;
    getline(cin, str);
    bracket b;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
            b.push('(');
        else if(str[i] == '[')
            b.push('[');
        else if(str[i] == ')')
            b.checkS();
        else if(str[i] == ']')
            b.checkB();
    }
}