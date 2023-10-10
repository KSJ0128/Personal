#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s; cin >> s;

    int n = 0;

    for(int i = 0; i < s.length();)
    {
        if(s.at(i) == 'c' && i + 1 < s.length())
        {
            if(s.at(i+1) == '=' || s.at(i+1) == '-')
            {
                n += 1;
                i += 2;
            }
            else
            {
                n += 1;
                i += 1;
            }
        }
        else if(s.at(i) == 'd' && i + 1 < s.length())
        {
            if(s.at(i+1) == 'z' && s.at(i+2) == '=' && i+1 < s.length())
            {
                n += 1;
                i += 3;
            }
            else if(s.at(i+1) == '-')
            {
                n += 1;
                i += 2;
            }
            else
            {
                n += 1;
                i += 1;
            }
        }
        else if((s.at(i) == 'l' || s.at(i) == 'n') && i + 1 < s.length())
        {
            if(s.at(i+1) == 'j')
            {
                n += 1;
                i += 2;
            }
            else
            {
                n += 1;
                i += 1;
            }
        }
        else if((s.at(i) == 's' || s.at(i) == 'z') && i + 1 < s.length())
        {   
            if(s.at(i+1) == '=')
            {
                n += 1;
                i += 2;
            }
            else
            {
                n += 1;
                i += 1;
            }
        }
        else
        {
            n += 1;
            i += 1;
        }
    }
    cout << n;
}