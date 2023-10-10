#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string pattern, str;
    cin >> N >> pattern;

    for(int i = 0; i < N; i++)
    {
        int pLength = pattern.length() - 1, check = 0;
        cin >> str;

        for(int j = 0; j < str.length(); j++)
        {
            if(pattern[j] == '*')
            {
                check = 1;
                break;
            }
            else
            {
                if(pattern[j] != str[j])
                    break;
            }
        }

        for(int k = str.length() - 1; k >= 0 && check == 1; k--, pLength--)
        {
            if(pattern[pLength] == '*')
            {
                check = 2;   
                break;
            }
            else
            {
                if(pattern[pLength] != str[k])
                    break;
            }
        }
        
        if(check == 2 && (str.length() >= pattern.length() - 1))
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
}