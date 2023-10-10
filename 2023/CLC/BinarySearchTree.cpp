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

    void setLeft(Node* n)
    {
        left = n;
    }

    void setRight(Node* n)
    {
        right = n;
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

    void setRoot(Node* n)
    {
        root = n;
    }

    Node* getRoot()
    {
        return root;
    }

    void insert(Node* r, Node* n)
    {
        if(r != NULL)
        {
            if(r->getData() > n->getData())
            {
                if(r->getLeft() == NULL)
                    r->setLeft(n);
                else
                    insert(r->getLeft(), n);
            }
            else
            {
                if(r->getRight() == NULL)
                    r->setRight(n);
                else
                    insert(r->getRight(), n);
            }
        }
    }

    void inOrder(Node* n) // 중위 순회
    {
        if(n != NULL)
        {
            if(n->getLeft() != NULL)
                inOrder(n->getLeft());
            cout << n -> getData() << " ";
            if(n->getRight() != NULL)
                inOrder(n->getRight());
        }
    }

    void preOrder(Node* n) // 전위 순회
    {
        if(n != NULL)
        {
            cout << n -> getData() << " ";
            if(n->getLeft() != NULL)
                preOrder(n->getLeft());
            if(n->getRight() != NULL)
                preOrder(n->getRight());
        }
    }

    void postOrder(Node* n) // 후위 순회
    {
        if(n != NULL)
        {
            if(n->getLeft() != NULL)
                postOrder(n->getLeft());
            if(n->getRight() != NULL)
                postOrder(n->getRight());
            cout << n -> getData() << " ";
        }
    }
};

int main()
{
    BinSrcTree tree;

    int N, key;
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
    
    cout << "PRE ORDER: ";
    tree.preOrder(tree.getRoot());
    cout << endl << "IN ORDER: ";
    tree.inOrder(tree.getRoot());
    cout << endl << "POST ORDER: ";
    tree.postOrder(tree.getRoot());
}