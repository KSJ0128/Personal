#include <iostream>
#include "Bracket.h"
using namespace std;

int main()
{
    Bracket bracket;
    char c;
    
    for(int i = 0; i < 6; i++)
    {
        cout << "괄호를 입력해주세요";
        cin >> c;

        if(c == '(' || c == '{' || c == '[')
        {
            bracket.push(c);
        }
        else if(c == ')' || c == '}' || c == ']')
        {
            if(bracket.isEmpty())   
            {
                cout << "괄호가 시작되지 않았습니다. 프로그램 종료합니다." << endl;
                return 0;
            }
            else
            {
                int check = bracket.pop(c);
                if(check == 0)
                {   
                    cout << "괄호의 짝이 맞지 않습니다. 프로그램 종료합니다." << endl;
                    return 0;
                }
            }
        }
    }   

    if(bracket.isEmpty())
    {
        cout << "괄호 검사 종료합니다." << endl;
    }
    else
    {
        cout << "괄호의 개수가 맞지 않습니다. 프로그램 종료합니다." << endl;
    }
}