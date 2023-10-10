#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<bool> self(10001, false);

    for(int i = 1; i < 10000; i++)
    {
        int num = i;
        string str = to_string(i);
        for(int j = 0; j < str.length(); j++)
            num += str[j] - '0';
        if(num <= 10000 && self[num] == false)
            self[num] = true;
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(self[i] == false)
            cout << i << '\n';
    }
}