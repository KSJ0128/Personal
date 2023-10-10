#include <iostream>
#include <string>
using namespace std;

int main()
{
    int alphabet[26] = {0,}, odd_cnt = 0, odd_i = -1;
    string name;
    char c = 'A';
    cin >> name;

    for(int i = 0; i < name.length(); i++)
    {
        alphabet[name[i] - 'A'] += 1;
        if(alphabet[name[i] - 'A'] % 2 == 1)
            odd_cnt += 1;
        else
            odd_cnt -= 1;
    }

    if(name.length() % 2 == 0 && odd_cnt == 0)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < alphabet[j] / 2; k++)
                cout << (char)('A' + j);
        }
        for(int j = 25; j >= 0; j--)
        {
            for(int k = 0; k < alphabet[j] / 2; k++)
                cout << (char)('A' + j);
        }
    }
    else if(name.length() % 2 == 1 && odd_cnt == 1)
    {
        for(int j = 0; j < 26; j++)
        {
            if(alphabet[j] % 2 == 1)
                odd_i = j;
            for(int k = 0; k < alphabet[j] / 2; k++)
                cout << (char)('A' + j);
        }
        cout << (char)('A' + odd_i);
        for(int j = 25; j >= 0; j--)
        {
            for(int k = 0; k < alphabet[j] / 2; k++)
                cout << (char)('A' + j);
        }
    }
    else
        cout << "I'm Sorry Hansoo";
}