#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string S, diff[1000];
    cin >> S;
    int cnt = 0, len = S.length();

    for(int i = 1; i <= len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(j + i > len)
                break;
            diff[j] = S.substr(j, i);
        }

        sort(diff, diff + len + 1 - i);
        for(int k = 0; k <= len - i; k++)
        {
            if(k == 0 || (diff[k].compare(diff[k-1]) != 0))
                cnt++;
        }
    }
    cout << cnt;
}