#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int N, arr[1000000] = {0,}, NGE[1000000] = {0,};
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        NGE[i] = -1;
    }
    
    st.push(arr[N-1]);
    
    for(int j = N-2; j >= 0; j--)
    {
        while(!st.empty())
        {
            if(arr[j] < st.top())
            {
                NGE[j] = st.top();
                break;
            }
            else
                st.pop();
        }
        st.push(arr[j]);
    }

    for(int k = 0; k < N; k++)
    {
        if(k == N-1)
            cout << NGE[k];
        else
            cout << NGE[k] << " ";
    }
}