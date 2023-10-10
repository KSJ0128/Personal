#include <iostream>
#include <string>
using namespace std;
int main()
{
    int count = 1;
    string s;
    getline(cin, s);

    // 입력 없는 경우
    if(s.size() == 0)
        cout << 0;
    else if(s.size() == 1)
    {
        // 공백 하나 입력된 경우
        if(s[0] ==' ')
            cout << 0;
        // 문자 하나가 입력된 경우
        else
            cout << count;
    }
    else
    {
        // 일반적인 경우
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                // 공백으로 시작하는 경우
                // 공백으로 끝나는 경우
                if(i == 0 || i == s.size()-1)
                    continue;
                else 
                    count++;
            }
        }

        cout << count;
    }
}