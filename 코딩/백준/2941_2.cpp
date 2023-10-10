#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cnt = 0;
    string alphabet;
    cin >> alphabet;

    for(int i = 0; i < alphabet.length(); i++)
    {
        if(i == alphabet.length()-1)
            cnt++;
        else if(alphabet.at(i) == 'c')
        {
            if(alphabet.at(i+1) == '=' || alphabet.at(i+1) == '-')
                i++;
            cnt++;
        }
        else if(alphabet.at(i) == 'd')
        {
            if(alphabet.at(i+1) == '-')
                i++;
            else if(i < alphabet.length()-2 && alphabet.at(i+1) == 'z' && alphabet.at(i+2) == '=')
                i += 2;
            cnt++;
        }
        else if(alphabet.at(i) == 'l' && alphabet.at(i+1) == 'j')
        {
            i++;
            cnt++;
        }
        else if(alphabet.at(i) == 'n' && alphabet.at(i+1) == 'j')
        {
            i++;
            cnt++;
        }
        else if(alphabet.at(i) == 's' && alphabet.at(i+1) == '=')
        {
            i++;
            cnt++;
        }
        else if(alphabet.at(i) == 'z' && alphabet.at(i+1) == '=')
        {
            i++;
            cnt++;
        }
        else
            cnt++;
    }
    cout << cnt;
}