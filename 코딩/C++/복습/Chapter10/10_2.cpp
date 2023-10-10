#include <iostream>
using namespace std;

string commonChars(const string& s1, const string& s2)
{
    bool check1[26] = {false};
    bool check2[26] = {false}; // 배열 false로 초기화
    int index = 0;
    string common("");

    for(int i = 0; i < s1.length(); i++)
    {
        int index1 = s1.at(i) - 'a';
        check1[index + index1] = true;
    }

    for(int j = 0; j < s2.length(); j++)
    {
        int index2 = s2.at(j) - 'a';
        check2[index + index2] = true;
    }

    for(int k = 0; k < 26; k++)
    {
        char c = 'a';
        
        if(check1[k] == check2[k] && check1[k] == true)
        {
            common.append(1, c+k);
        }
    }

    return common;
}

int main()
{
    string s1, s2;
    cout << "string s1, s2를 입력해주세요.";
    cin >> s1 >> s2;

    cout << "공통 문자는 " << commonChars(s1, s2) << " 입니다.";
}