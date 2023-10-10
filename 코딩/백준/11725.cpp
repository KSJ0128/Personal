#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    vector<int> parent;
    cin >> N;
    parent.resize(N+1);
    
    for(int i = 2; i < N+1; i++)
        parent.push_back(0);

    for(int i = 0; i < N-1; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        if(n1 == 1 || n2 == 1) // 루트 노드일 때
        {
            if(n1 == 1)
                parent[n2] = 1;
            else
                parent[n1] = 1;
        }
        else if(parent[n1] == 0)
            parent[n1] = n2;
        else
            parent[n2] = n1;
    }

    for(int i = 2; i < N+1; i++)
        cout << parent[i] << '\n';
}