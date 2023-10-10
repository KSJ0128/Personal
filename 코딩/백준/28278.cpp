#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int N;
    stack<int> st;
    char order[10];
    cin >> N;
    
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i <= N; i++) 
    {
        cin.getline(order, sizeof(order));
        if(order[0] == '2')
        {
            if(st.empty())
                cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(order[0] == '3')
            cout << st.size() << '\n';
        else if(order[0] == '4')
        {
            if(st.empty())
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
        }
        else if(order[0] == '5')
        {
            if(st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
        else if(order[0] == '1')
        {
            int i = atoi(order + 2);
            st.push(i);
        }
    }
}