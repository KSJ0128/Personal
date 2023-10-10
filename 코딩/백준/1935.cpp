#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int N;
    int operand[26];
    string str;
    stack<double> st;
    cin >> N >> str;

    for(int i = 0; i < N; i++)
        cin >> operand[i];

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            st.push(operand[str[i] - 'A']);
        else
        {
            double op2 = st.top();
            st.pop();
            double op1 = st.top();
            st.pop();
            if(str[i] == '+')
                st.push(op1 + op2);
            else if(str[i] == '-')
                st.push(op1 - op2);
            else if(str[i] == '*')
                st.push(op1 * op2);
            else if(str[i] == '/')
                st.push(op1 / op2);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
}