#include <iostream>
#include <vector>
using namespace std;

class BinaryNode
{
    public:
        int data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
        {
            data = val;
            left = l;
            right = r;
        }
        ~BinaryNode() { }

        void setData(int val) 
        { 
            data = val; 
        }
        void setLeft(BinaryNode* l) 
        { 
            left = l; 
        }
        void setRight(BinaryNode* r) 
        { 
            right = r; 
        }
        int getData() 
        { 
            return data; 
        }
        BinaryNode* getLeft() 
        { 
            return left; 
        }
        BinaryNode* getRight() 
        { 
            return right; 
        }
        bool isLeaf() 
        { 
            return left == NULL && right == NULL; 
        }
};
class BinaryTree
{
    BinaryNode* root;

    public:
    BinaryTree()
    { 
        root = NULL;
    }
    ~BinaryTree(){}

    void setRoot(BinaryNode* node) 
    { 
        root = node; 
    }
    BinaryNode* getRoot() 
    { 
        return root; 
    }
};   

int N;
vector<bool> visited;
vector<int> answer;
vector< vector<int> > tree;

void DFS(int num)
{
    visited[num] = true;
    for(int i : tree[num])
    {
        if(!visited[i])
        {
            answer[i] = num;
            DFS(i);
        }
    }
}

int main()
{
    cin >> N;
    visited.resize(N+1);
    answer.resize(N+1);
    tree.resize(N+1);

    for(int i = 1; i < N; i++) // tree setting
    {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    DFS(1);

    for(int i = 2; i <= N; i++)
        cout << answer[i] << endl;
}