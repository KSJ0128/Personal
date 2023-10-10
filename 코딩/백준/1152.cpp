#include <iostream>
#include <string>
using namespace std;
int main()
{
    int space = 1;

    string s; getline(cin, s, '\n'); 
    // cin으로 입력 받으면 공백 포함 안되므로 getline으로 받기
    
    if(s.length() > 1)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s.at(i) == ' ') // 공백 있는 경우
            {  
                if(i != 0 && i != s.length()-1) // 공백이 문장 맨 앞과 끝에 위치하지 않는 경우
                    space += 1;
            }
        }
        cout << space;
    }
    else
    { 
        if(s[0]!=' ') // 1글자만 있는 경우
            cout << 1;
        else // 공백만 있는 경우
            cout << 0;
    }
       
}