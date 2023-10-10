#include <iostream>
#include <vector>
using namespace std;

class BinaryNode
{
    public:
        char data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(char val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
        {
            data = val;
            left = l;
            right = r;
        }
        ~BinaryNode() { }

        void setData(char val) 
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
        char getData() 
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
    void inorder()     
    {   
        inorder(root);     
    }
    void preorder()   
    { 
        preorder(root);   
    }
    void postorder() 
    { 
        postorder(root);
    }

    private:
        void inorder(BinaryNode* node) 
        {
            if (node != NULL) 
            {
                if (node->getLeft() != NULL) 
                    inorder(node->getLeft());
                cout << node->getData(); 
                if (node->getRight() != NULL) 
                    inorder(node->getRight());
            }
        }

        void preorder(BinaryNode* node) 
        {
            if (node != NULL) 
            {
                cout << node->getData();
                if (node->getLeft() != NULL) 
                    preorder(node->getLeft());
                if (node->getRight() != NULL) 
                    preorder(node->getRight());
            }
        }

        void postorder(BinaryNode* node) 
        {
            if (node != NULL) 
            {
                if (node->getLeft() != NULL) 
                    postorder(node->getLeft());
                if (node->getRight() != NULL) 
                    postorder(node->getRight());
                cout << node->getData();
            }
        }
};

int main()
{
    int N;
    char p, l, r;
    BinaryTree tree;
    cin >> N;
    vector<BinaryNode*> nodes(N);

    for(int j = 0; j < N; j++)
        nodes[j] = new BinaryNode('A' + j);

    for(int i = 0; i < N; i++)
    {
        cin >> p >> l >> r;

        if(l != '.')
            nodes[p - 'A']->setLeft(nodes[l - 'A']);
        else
            nodes[p - 'A']->setLeft(NULL);

        if(r != '.')
            nodes[p - 'A']->setRight(nodes[r - 'A']);
        else
            nodes[p - 'A']->setRight(NULL);
    }
    tree.setRoot(nodes[0]);
    tree.preorder();
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.postorder();
}