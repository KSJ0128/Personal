#include <iostream>
#include <vector>
using namespace std;

class BinaryNode
{
    public:
        int data;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;

        BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL, BinaryNode* p = NULL)
        {
            data = val;
            left = l;
            right = r;
            parent = p;
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
        void setParent(BinaryNode* p) 
        { 
            parent = p; 
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
        BinaryNode* getParent() 
        { 
            return parent; 
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
    bool isEmpty() 
    { 
        return root == NULL; 
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, n1, n2;
    BinaryTree tree;
    cin >> N;
    vector<BinaryNode*> nodes(N + 1);
    
    for(int i = 1; i <= N; i++)
        nodes[i] = new BinaryNode(i);
    
    for(int i = 1; i < N; i++)
    {
        cin >> n1 >> n2;

        if(n1 == 1 || nodes[n1]->getParent() != NULL) // 자식 세팅
        {
            if(nodes[n1]->getLeft() == NULL)
                nodes[n1]->setLeft(nodes[n2]);
            else
                nodes[n1]->setRight(nodes[n2]);
            nodes[n2]->setParent(nodes[n1]);
        }
        else
        {
            if(nodes[n2]->getLeft() == NULL)
                nodes[n2]->setLeft(nodes[n1]);
            else
                nodes[n2]->setRight(nodes[n1]);
            nodes[n1]->setParent(nodes[n2]);
        }
    }

    for(int i = 2; i <= N; i++)
        cout << nodes[i]->getParent()->getData() << '\n';
}