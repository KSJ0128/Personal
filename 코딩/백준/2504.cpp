#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int num = 0, tmp = 1;
    bool status = true;
    string par;
    stack<char> st;
    cin >> par;

    for(int i = 0; i < par.length(); i++)
    {
        if(par.at(i) == '(' || par.at(i) == '[')
        {
            st.push(par.at(i));
            if(i != 0 && (par.at(i-1) == ')' || par.at(i-1) == ']') && tmp != 1)
            {
                num += tmp;
                tmp = 1;
            }
        }
        else
        {
            if(par.at(i) == ')' && st.top() =='(')
            {
                st.pop();
                tmp *= 2;
            }
            else if(par.at(i) == ']' && st.top() =='[')
            {
                st.pop();
                tmp *= 3;
            }
            else           
            {
                status = false;
                break;
            }
            
            if(st.empty())
            {
                num += tmp;
                tmp = 1;
            }
        }
    }
    
    if(status == false)
        cout << 0;
    else
        cout << num;
}