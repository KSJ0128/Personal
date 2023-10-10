#include <iostream>
#define MAX_QUEUE 100
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
class CircularQueue 
{
    public:
	BinaryNode* arr[MAX_QUEUE];
	int front = 0, rear = 0;

	BinaryNode* getFront() 
    { 
        return arr[front]; 
    }
	bool isEmpty() 
    { 
        return (front == rear); 
    }
	bool isFull() 
    { 
        return ((rear + 1) % MAX_QUEUE == front); 
    }
	int size() 
    { 
        return (front > rear ? front - rear : rear - front); 
    }
	void enqueue(BinaryNode* node) 
	{ 
		if (isFull()) 
            cout << "Queue is FULL!\n";
		else 
		{
			arr[rear] = node;
			rear = (rear + 1) % MAX_QUEUE;
		}
	}
	BinaryNode* dequeue() 
	{
		if (isEmpty()) 
            cout << "Queue is Empty!\n";
		else 
        {
            int tmp = front;
            front = (front + 1) % MAX_QUEUE;
            return arr[tmp];
        }
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

    // Tree Operation
    int getCount() // 노드 개수
    {
        return isEmpty() ? 0 : getCount(root);
    }	
    int getLeafCount()	// 단말 노드 개수
    {
        return isEmpty() ? 0 : getLeafCount(root);
    }	
    int getHeight()	// 트리의 높이
    {
        return isEmpty() ? 0 : getHeight(root);
    }
    bool isFull() // full binary tree인지 
    {
        return isEmpty() ? true : isFull(root);
    }	
    int calcLevel(int n)  	// 데이터가 n인 노드의 레벨
    {
        return isEmpty() ? 0 : calcLevel(root, n, 1);
    }

    int getCount(BinaryNode* node)
    {
        if( node == NULL ) 
            return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }
    int getLeafCount(BinaryNode* node)
    {
        if (node == NULL) 
            return 0;
        if (node->isLeaf()) 
            return 1;
        else 
            return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());

    }
    int getHeight(BinaryNode* node)
    {
        if(node == NULL) 
            return 0;
        int lHeight = getHeight(node->getLeft());   // 왼쪽 서브트리 높이 계산
        int rHeight = getHeight(node->getRight());  // 오른쪽 서브트리 높이 계산
        return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
    }
    bool isFull(BinaryNode* node)
    {
        if(node == NULL)
            return true;
        if(node->left == NULL && node->right == NULL)
            return true;
        if(node->left != NULL && node->right != NULL)
            return isFull(node->left) && isFull(node->right);
        else
            return false;
    }
    int calcLevel(BinaryNode* node, int n, int level)
    {
        if(node == NULL)
            return 0;
        if(node->data == n)
            return level;
        int ll = calcLevel(node->left, n, level + 1);
        if(ll != 0)
            return ll;
        ll = calcLevel(node->right, n, level + 1);
        return ll;
    }
    void inorder()     
    {   
        cout << endl << "inorder: ";       
        inorder(root);     
    }
    void preorder()   
    { 
        cout << endl << "preorder: ";    
        preorder(root);   
    }
    void postorder() 
    { 
        cout << endl << "postorder: ";   
        postorder(root);
    }
    void BinaryTree::levelorder() 
    {
        cout << endl << "levelorder: ";
        if (!isEmpty()) 
        {
            CircularQueue q;
            q.enqueue(root);
            while (!q.isEmpty()) 
            {
                BinaryNode* n = q.dequeue();
                if (n != NULL) 
                {
                    cout << " [" << n->getData() << "] ";
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        cout << endl;
    }

    private:
        void BinaryTree::inorder(BinaryNode* node) 
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

        void BinaryTree::preorder(BinaryNode* node) 
        {
            if (node != NULL) 
            {
                cout << "[" << node->getData() << "] ";
                if (node->getLeft() != NULL) 
                    preorder(node->getLeft());
                if (node->getRight() != NULL) 
                    preorder(node->getRight());
            }
        }

        void BinaryTree::postorder(BinaryNode* node) 
        {
            if (node != NULL) 
            {
                if (node->getLeft() != NULL) 
                    postorder(node->getLeft());
                if (node->getRight() != NULL) 
                    postorder(node->getRight());
                cout << "[" << node->getData() << "] ";
            }
        }
};