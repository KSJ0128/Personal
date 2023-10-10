#include <iostream>
#include <string>
using namespace std;

string swapCase(const string& s)
{
    string reverse;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] > 'A' && s[i] <= 'Z')
            reverse += tolower(s[i]);
        else if(s[i] > 'a' && s[i] <= 'z')
            reverse += toupper(s[i]);
        else
            reverse += s[i];
    }

    return reverse;
}

/*
소문자 체크
islower()

대문자 체크
isupper()
*/

int main()
{
    string str;

    getline(cin, str); // 공백 포함 문자열 입력 받기
    cout << swapCase(str);
}