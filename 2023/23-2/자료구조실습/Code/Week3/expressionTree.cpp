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
    int evaluate()
    {
        return evaluate(root);
    }

    private:
        int evaluate(BinaryNode* node)
        {
            if(node == NULL)
                return 0;
            if(node->isLeaf())
                return node->getData();
            else
            {
                int op1 = evaluate(node->getLeft());
                int op2 = evaluate(node->getRight());

                switch((char)node->getData())
                {
                    case '+': return op1 + op2;
                    case '-': return op1 - op2;
                    case '*': return op1 * op2;
                    case '/': return op1 / op2;
                    default: return 0;
                }
            }
        }
};

int main()
{
    char oper;
    int N, operand, l, r;
    cin >> N;
    vector<BinaryNode*> nodes(2 * N);
    BinaryTree tree;

    for(int i = 1; i < 2 * N; i++)
        nodes[i] = new BinaryNode(0);

    for(int i = 1; i <= N; i++)
    {
        cin >> operand;
        nodes[i]->setData(operand);
    }

    for(int j = N + 1; j < 2 * N; j++)
    {
        cin >> oper >> l >> r;
        nodes[j]->setData(oper);

        nodes[j]->setLeft(nodes[l]);
        nodes[l]->setParent(nodes[j]);

        nodes[j]->setRight(nodes[r]);
        nodes[r]->setParent(nodes[j]);
    }

    for(int j = N + 1; j < 2 * N; j++)
    {
        if(nodes[j]->getParent() == NULL)
        {
            tree.setRoot(nodes[j]);
            break;
        }
    }
    cout << tree.evaluate();
}