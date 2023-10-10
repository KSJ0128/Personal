#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> cookie;
    int N, l_arm = 1, r_arm = 1, l_leg = 1, r_leg = 1, waist = 1, x, y;
    cin >> N;
    cookie.resize(N);

    for(int i = 0; i < N; i++)
        cin >> cookie[i];
    
    for(int i = 1; i < N-1; i++) // 심장 찾기
    {
        for(int j = 1; j < N-1; j++)
        {
            if(cookie[i][j] == '*')
            {
                if(cookie[i-1][j] == '*' && cookie[i][j-1] == '*' && 
                        cookie[i][j+1] == '*' && cookie[i+1][j] == '*') 
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= y; i++) // left arm
    {
        if(i == y && cookie[x][y - i] == '*')
        {
            l_arm = i;
            break;
        }
        else if(cookie[x][y - i] == '_')
        {
            l_arm = i - 1;
            break;
        }
    }
    for(int i = 1; i + y < N; i++) // right arm
    {
        if(y + i == N-1 && cookie[x][y + i] == '*')
        {
            r_arm = i;
            break;
        }
        else if(cookie[x][y + i] == '_')
        {
            r_arm = i - 1;
            break;
        }
    }
    for(int i = 1; x + i < N - 1; i++) // waist
    {
        if(x + i == N-2 && cookie[x + i][y] == '*')
        {
            waist = i;
            break;
        }
        else if(cookie[x + i][y] == '_')
        {
            waist = i - 1;
            break;
        }
    }
    for(int i = 1; i + y < N; i++) // left leg
    {
        if(x + waist + i == N-1 && cookie[x + waist + i][y - 1] == '*')
        {
            l_leg = i;
            break;
        }
        else if(cookie[x + waist + i][y - 1] == '_')
        {
            l_leg = i - 1;
            break;
        }
    }
    for(int i = 1; i + y < N; i++) // right leg
    {
        if(x + waist + i == N-1 && cookie[x + waist + i][y + 1] == '*')
        {
            r_leg = i;
            break;
        }
        else if(cookie[x + waist + i][y + 1] == '_')
        {
            r_leg = i - 1;
            break;
        }
    }
    cout << x+1 << ' ' << y+1 << '\n';
    cout << l_arm << ' ' << r_arm << ' ' << waist << ' ' << l_leg << ' ' << r_leg;
}