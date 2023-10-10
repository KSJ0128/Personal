#include <iostream>
#include <string>
using namespace std;

// 코드 복사.
int count(const string& s, char a)
{
    int count; // 문자열에 속한 문자의 개수

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == a) 
            count++;
    }
    
    return count;
}

int main()
{
    string s;
    char a;

    getline(cin, s);
    
    cin >> a;
    
    cout << count(s, a);
}