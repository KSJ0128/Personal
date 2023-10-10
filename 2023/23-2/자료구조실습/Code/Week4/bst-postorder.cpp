#include <iostream>
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
    protected:
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

    // Tree Operation
    int getCount() // 노드 개수
    {
        return isEmpty() ? 0 : getCount(root);
    }
    int getHeight()	// 트리의 높이
    {
        return isEmpty() ? 0 : getHeight(root);
    }
    int getCount(BinaryNode* node)
    {
        if( node == NULL ) 
            return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }
    int getHeight(BinaryNode* node)
    {
        if(node == NULL) 
            return 0;
        int lHeight = getHeight(node->getLeft());   // 왼쪽 서브트리 높이 계산
        int rHeight = getHeight(node->getRight());  // 오른쪽 서브트리 높이 계산
        return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
    }
    void inorder()     
    {   
        cout << endl << "inorder: ";       
        inorder(root);     
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
                cout << "[" << node->getData() << "] "; 
                if (node->getRight() != NULL) 
                    inorder(node->getRight());
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
                cout << node->getData() << '\n';
            }
        }
};
class BinSrchTree : public BinaryTree
{
    public:
    BinSrchTree(void) { }
    ~BinSrchTree(void) { }

    BinaryNode* search(int key) 
    {
        //!!! parent class변수: root=> protected
        BinaryNode* node = search(root, key);
        return node;
    }
    BinaryNode* search(BinaryNode* n, int key) 
    {
        if (n == NULL) 
            return NULL;
        if (key == n->getData()) 
            return n;
        else if (key < n->getData()) 
            return search(n->getLeft(), key);
        else return 
            search(n->getRight(), key);
    }
    void insert( BinaryNode* n ) 
    {
        if( n == NULL ) 
            return;
        if( isEmpty() ) 
            root = n;
        else 
            insert( root, n );
    }
    void insert( BinaryNode* r, BinaryNode* n ) 
    {
        if( n->getData() == r->getData() ) 
            return;
        else if( n->getData() < r->getData() ) 
        {
            if( r->getLeft() == NULL ) 
                r->setLeft(n);
            else 
                insert( r->getLeft(), n );
        }
        else {
            if( r->getRight() == NULL ) 
                r->setRight(n);
            else 
                insert( r->getRight(), n );
        }
    }
    // void remove(int key);
    // void remove(BinaryNode* parent, BinaryNode* node);
};


int main()
{
    // 입출력 빠르게 해주는 코드
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    BinSrchTree tree;
    int data;

    while(cin >> data)
        tree.insert(new BinaryNode(data));
    tree.postorder();
}