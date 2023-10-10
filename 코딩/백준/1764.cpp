#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> listen;
    vector<string> see;
    vector<string> listenSee;
    int N, M;
    cin >> N >> M;

    listen.resize(N);
    see.resize(M);
    for(int i = 0; i < N; i++)
        cin >> listen[i];
    for(int j = 0; j < M; j++)
        cin >> see[j];
    
    sort(listen.begin(), listen.end());
    sort(see.begin(), see.end());

    for(int i = 0; i < N; i++)
    {
        if(binary_search(see.begin(), see.end(), listen[i]))
            listenSee.push_back(listen[i]);
    }

    sort(listenSee.begin(), listenSee.end());
    cout << listenSee.size() << '\n';
    for(int i = 0; i < listenSee.size(); i++)
        cout << listenSee[i] << '\n';
}