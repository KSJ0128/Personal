#include <iostream>
using namespace std;
int main()
{
    int N, score = 0, count = 0;
    cin >> N;
    string s;

    for(int i = 0; i < N; i++)
    {
        cin >> s; // 케이스별 입력

        for(int j = 0; j < s.length();j++)
        {
            if(s[j] == 'O')
            {
                count++;
                score += count;
            }
            else if(s[j] == 'X')
            {
                count = 0;
            }
        }
        cout << score << endl;
        score = 0;
        count = 0;
    }
}