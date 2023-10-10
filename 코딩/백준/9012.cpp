#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T; cin >> T;
    int left, right = 0;
    string result[T];

    for(int i = 0; i < T; i++)
    {
        string s; cin >> s;
        left = 0; right = 0; // left, right 초기화하는 게 포인트

        for(int j = 0; j < s.length(); j++)
        {
            if(s.at(j) == '(')
                left+=1;
            else 
            {
                right+=1;

                if(right > left)
                    break;
            }    

        }
        if(left != right)
        {
            result[i] = "NO";
        }
        else if(left == right)
        {
            if(s.at(0) == '(' && s.at(s.length()-1) == ')')
                result[i] = "YES";
            else
                result[i] = "NO";
        }
        
    }

    for(int i = 0; i < T; i++)
        cout << result[i] << endl;
}