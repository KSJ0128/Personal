#include <iostream>
#include <algorithm>
#define MAX_COUNT 500
using namespace std;

void search(int i, int j, int& h, int danji[][25], int visited[][25]) {
    
    if(j-1 >= 0 && visited[i][j-1] == 0) // left
    {
        visited[i][j-1] = 1;
        
        if(danji[i][j-1] == 1)
            search(i, j-1, ++h, danji, visited);
    }
    
    if(j+1 < 25 && visited[i][j+1] == 0) // right
    {
        visited[i][j+1] = 1;

        if(danji[i][j+1] == 1)
            search(i, j+1, ++h, danji, visited);
    }
    
    if(i-1 >= 0 && visited[i-1][j] == 0) // top
    {
        visited[i-1][j] = 1;

        if(danji[i-1][j] == 1)
            search(i-1, j, ++h, danji, visited);
    }
    
    if(i+1 < 25 && visited[i+1][j] == 0) // bottom
    {
        visited[i+1][j] = 1;

        if(danji[i+1][j] == 1)
            search(i+1, j, ++h, danji, visited);
    }
}

int main()
{
    int N, dCount = -1, hCount[MAX_COUNT], danji[25][25] = {0}, visited[25][25] = {0};
    string d = "";

    cin >> N;

    for(int i = 0; i < N; i++) // danji 초기화
    {
        cin >> d;

        for(int j = 0; j < N; j++)
        {
            if(d.at(j)== '1')
                danji[i][j] = 1;
        }
    }

    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++)
        {
            if(visited[i][j] == 0) {
                visited[i][j] = 1;

                if(danji[i][j] == 1) {
                    int h = 1;
                    search(i, j, h, danji, visited);
                    hCount[++dCount] = h;
                }
                else
                    continue;
            }
            else
                continue;
        }
    }

    sort(hCount, hCount+dCount+1);

    cout << dCount+1 << endl;

    for(int i = 0; i < dCount+1; i++)
    {
        cout << hCount[i] << endl;
    }
}