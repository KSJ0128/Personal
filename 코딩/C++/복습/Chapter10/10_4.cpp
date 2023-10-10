#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sort1(string& s) // sort 함수 사용한 경우
{
    string sortedString(s);
    sort(sortedString.begin(), sortedString.end());

    return sortedString;
}

int main()
{
    string s; 
    cout << "문자열을 입력해주세요.";
    cin >> s;

    cout << "정렬된 문자열: " << sort1(s);
}