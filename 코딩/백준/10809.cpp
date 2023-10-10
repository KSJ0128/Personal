#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;

    for(int i = 0; i < 26; i++)
    {
        if (S.find('a'+i) != string::npos)
            cout << S.find('a'+i) << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}