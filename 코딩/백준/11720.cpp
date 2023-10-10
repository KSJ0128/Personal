#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, num = 0;
    string str;
    
    cin >> N >> str;

    for (int i = 0; i < N; i++)
        num += str[i] - '0';

    cout << num;
    return 0;
}