#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M;
    vector<int> set(21, 0);
    cin >> M;
    cin.ignore();

    for(int i = 0; i < M; i++)
    {
        string order;
        getline(cin, order);

        if(order.substr(0,3) == "add") // add x
        {
            int num = atoi(order.substr(4).c_str());
            if(set[num] == 0)
                set[num] = 1;
        }
        else if(order.substr(0,6) == "remove") // remove x
        {
            int num = atoi(order.substr(7).c_str());
            if(set[num] == 1)
                set[num] = 0;
        }
        else if(order.substr(0,5) == "check") // check x
        {
            int num = atoi(order.substr(6).c_str());
            if(set[num] == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(order.substr(0,6) == "toggle") // toggle x
        {
            int num = atoi(order.substr(7).c_str());
            if(set[num] == 1)
                set[num] = 0;
            else
                set[num] = 1;
        }
        else if(order[0] == 'a' && order[1] == 'l') // all
        {
            for(int j = 1; j <= 20; j++)
                set[j] = 1;
        }
        else // empty
        {
            for(int j = 1; j <= 20; j++)
                set[j] = 0;
        }
    }
}