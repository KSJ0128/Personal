#include <iostream>
using namespace std;

class Bracket
{
    private:
    char bracketList[10];
    int index;

    public:
    Bracket()
    {
        index = -1;
    }

    void push(char c)
    {
        bracketList[++index] = c;
    }

    int pop(char c)
    {
        if(c == ')' && bracketList[index] == '(')
        {
            bracketList[index--];
            cout << "소괄호가 삭제됐습니다." << endl;
            return 1;
        }
        else if(c == '}' && bracketList[index] == '{')
        {
            bracketList[index--];
            cout << "중괄호가 삭제됐습니다." << endl;
            return 1;
        }
        else if(c == ']' && bracketList[index] == '[')
        {
            bracketList[index--];
            cout << "대괄호가 삭제됐습니다." << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isEmpty()
    {
        return index == -1;
    }
};