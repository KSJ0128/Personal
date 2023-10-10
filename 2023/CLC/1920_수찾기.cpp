#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;

    public:
    Node(int d, Node* l = NULL, Node* r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }

    void setLeft(Node* l)
    {
        left = l;
    }
    void setRight(Node* r)
    {
        right = r;
    }
    
    void setData(int key)
    {
        data = key;
    }

    Node* getLeft()
    {
        return left;
    }

    Node* getRight()
    {
        return right;
    }

    int getData()
    {
        return data;
    }
};

class BinSrcTree
{
    Node* root;

    public:
    BinSrcTree()
    {
        root = NULL;
    }

    Node* getRoot()
    {
        return root;
    }

    void setRoot(Node* n)
    {
        root = n;
    }

    void insert(Node* r, Node* n)
    {
        if(n->getData() > r->getData())
        {
            if(r->getRight() == NULL)
                r->setRight(n);
            else
                insert(r->getRight(), n);
        }
        else
        {
            if(r->getLeft() == NULL)
                r->setLeft(n);
            else
                insert(r->getLeft(), n);
        }
    }

    Node* search(Node* n, int key)
    {
        if(n == NULL)
            return NULL;
        else
        {
            if(key == n->getData())
                return n;
            else if(key > n->getData())
                return search(n->getRight(), key);
            else
                return search(n->getLeft(), key);
        }
    }
};

int main()
{
    // 입출력 빠르게 해주는 코드
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    BinSrcTree tree;
    int N, M, key;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> key;
        
        if(i == 0)
            tree.setRoot(new Node(key));
        else
        {
            tree.insert(tree.getRoot(), new Node(key));
        }
    }

    cin >> M;

    for(int j = 0; j < M; j++)
    {
        cin >> key;

        Node* node = tree.search(tree.getRoot(), key);

        if(node == NULL)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }
}