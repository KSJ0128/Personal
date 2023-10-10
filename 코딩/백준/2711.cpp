#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T, pos;
    string str;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> pos >> str;
        str.erase(pos-1, 1);
        cout << str << '\n';
    }
}