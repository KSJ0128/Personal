#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> position;
    int N, width = 0, height = 0;
    cin >> N;

    position.resize(N);
    for(int i = 0; i < N; i++)
        cin >> position[i];
    
    for(int i = 0; i < N; i++) // 가로
    {
        for(int j = 0; j < N-1; j++)
        {
            if(position[i][j] == '.' && position[i][j+1] == '.')
            {
                width++;
                while(j < N && position[i][j] == '.')
                    j++;
            }
        }
    }

    for(int i = 0; i < N; i++) // 세로
    {
        for(int j = 0; j < N-1; j++)
        {
            if(position[j][i] == '.' && position[j+1][i] == '.')
            {
                height++;
                while(j < N && position[j][i] == '.')
                    j++;
            }
        }
    }

    cout << width << ' ' << height;
}