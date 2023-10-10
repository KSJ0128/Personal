#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, K, index, g, s, b, rank = 1;
    vector< vector<int> > medal;
    cin >> N >> K;
    medal.resize(N+1);

    for(int i = 0; i < N; i++)
    {
        cin >> index >> g >> s >> b;
        medal[index].push_back(g);
        medal[index].push_back(s);
        medal[index].push_back(b);
    }

    for(int i = 1; i <= N; i++)
    {
        if(i == K)
            continue;
        if(medal[i][0] > medal[K][0])
            rank++;
        else if(medal[i][0] == medal[K][0])
        {
            if(medal[i][1] > medal[K][1])
                rank++;
            else if(medal[i][1] == medal[K][1])
            {
                if(medal[i][2] > medal[K][2])
                    rank++;
            }
        }
    }
    cout << rank;
}