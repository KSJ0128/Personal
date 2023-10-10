#include <iostream>
using namespace std;

int count(const char s[], char a)
{
    int cnt = 0;

    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == a)
            cnt++;
    }

    return cnt;
}

int main()
{
    char s[100];
    char c;

    cin.getline(s, 100, '\n');

    cin >> c;

    cout << count(s, c);
}