#include <iostream>
#include <vector>
using namespace std;

int N;
int leaf;   
int deleteNode;
vector<bool> visited;
vector< vector<int> > tree; 

void DFS(int num)
{
    visited[num] = true;
    
    for(int i : tree[num])
    {
        if(!visited[i] && deleteNode != i)
        {
            if(tree[i].size() == 1) // 리프노드인 경우
                leaf++;
            else if(tree[i].size() == 2) // 자식이 1개인 경우인데 삭제 노드일 경우
            {
                if(tree[i][0] == num && tree[i][1] == deleteNode)
                    leaf++;
                else if(tree[i][1] == num && tree[i][0] == deleteNode)
                    leaf++;
            }

            DFS(i);
        }
    }
    if(leaf == 0)
        leaf++;
}

int main()
{
    cin >> N;
    visited.resize(N);
    tree.resize(N);

    int root;

    for(int i = 0; i < N; i++)
    {
        int node;
        cin >> node;

        if(node != -1)
        {
            tree[i].push_back(node);
            tree[node].push_back(i);
        }
        else
            root = i;
    }

    cin >> deleteNode;
    
    if(deleteNode == 0)
    {
        cout << 0;
    }
    else
    {
        DFS(root);
        cout << leaf;
    }
}