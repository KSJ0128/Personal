#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
/*
class BinaryNode 
{
	int data; // key 값이 됩니다. 
	BinaryNode* left; // 왼쪽 자식 노드 링크
	BinaryNode* right; // 오른쪽 자식 노드 링크

    public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
	{
        data = val;
        left = l;
        right = r;
    }

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
};

class BinaryTree
{
    private:
    int count;
    BinaryNode* root;

    public:
    BinaryTree()
    {
        root = NULL;
        count = 0;
    }

    void setRoot(BinaryNode* node) { root = node; } // 내가 원하는 node로 root를 만들어 줍니다.
    BinaryNode* getRoot() { return root; }
    int getCount() { return count; }
    void countUp() { count++; }

    void inorder() // 외부에서 사용하면
    { 
        cout << "inorder: "; // inorder를 사용했다고 콘솔창에 출력한 뒤에, 
        inorder(root);		// root부터 inorder 함수의 recursion을 시작합니다. 
    }

    void inorder(BinaryNode* node) 
    {
        countUp();
        if (node != NULL) 
        {
            cout << " [" << node->getData() << "] "; 
            // node 가 포인터 객체니까 -> 써서 멤버 함수를 호출합니다.
            
            if (node->getLeft() != NULL) 
                inorder(node->getLeft());

            if (node->getRight() != NULL) 
                inorder(node->getRight());
        }
    }

    BinaryNode* search(int key) // 외부 호출
    {
        BinaryNode* node = search(root, key);
        
        if(node != NULL)
            return node;
        else
            return NULL;
    } 

	BinaryNode* search(BinaryNode* n, int key) // 내부 recursion
    {
        if( n == NULL ) 
            return NULL;

        if( n->getData() == key )
            return n;
        else
        {
            search(n->getLeft(), key);
            search(n->getRight(), key);
        }
    }
};

int main()
{
    BinaryTree tree;
    int N, a, b, c;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;

        if(i == 0)
        {
            tree.setRoot(new BinaryNode(a));
            BinaryNode* node = tree.getRoot();
            
            if(b != -1)
            {
                node->setLeft(new BinaryNode(b));
            }
            if(c != -1)
            {
                node->setRight(new BinaryNode(c));
            }
        }   
        else
        {
            BinaryNode* node = tree.search(a);

            if(b != -1)
            {
                node->setLeft(new BinaryNode(b));
            }
            if(c != -1)
            {
                node->setRight(new BinaryNode(c));
            }
        }
    }

    tree.inorder();
    cout << tree.getCount();
}
*/
/* class Node
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

    int getData()
    {
        return data;
    }

    Node* getLeft()
    {
        return left;
    }

    Node* getRight()
    {
        return right;
    }

    void setLeft(Node* l)
    {
        left = l;
    }

    void setRight(Node* r)
    {
        right = r;
    }
};

class BinSrchTree
{
    Node* root;

    public:
    BinSrchTree()
    {
        root = NULL;
    }

    void set(Node* n, Node* l, Node* r)
    {
        root = n;
        root->setLeft(l);
        root->setRight(r);
    }

    Node* search(int key)
    {
        Node* n = search(root, key);

        if(n == NULL)
            return NULL;
        return n;
    }

    Node* search(Node* n, int key)
    {
        if(n->getData() == key)
            return n;
        else
        {
            search(n->getLeft(), key);
            search(n->getRight(), key);
        }
    }

    void inOrder()
    {
        cout << "INORDER: ";
        inOrder(root);
    }

    void inOrder(Node* n)
    {
        if(n != NULL)
        {
            cout << n->getData() << " ";
            if(n->getLeft() != NULL)
                inOrder(n->getLeft());
            if(n->getRight() != NULL)
                inOrder(n->getRight());
        }
    }
};

int main()
{
    int N, a, b, c;
    BinSrchTree tree;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;

        if(i == 0) // 루트 설정
        {
            tree.set(new Node(1), new Node(b), new Node(c));
        }
        else if(b != -1 || c != -1) // 노드 설정
        {
            Node* node = tree.search(a);

            if(b != -1)
                node->setLeft(new Node(b));
            if(c != -1)
                node->setRight(new Node(c));
        }
        else
            continue;
    }
    tree.inOrder();
}
*/

int N, Data, Left, Right;
int cnt = -1, Rcnt = -1; // 최초 노드 카운트는 제외해야하기 때문에 -1로 설정

map<int, pair<int, int>> tree;

void input() // 트리에 노드 insert <Data, <left, right>>
{
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cin >> Data >> Left >> Right;

        //Data가 중복되면 알아서 좌우로 들어간다.
        tree[Data].first = Left; 
        tree[Data].second = Right;
    }
}

// flag : 루트노드 기준 좌측 트리 우측트리 구분자
void travel(int node, bool flag) 
{
    // 해당노드가 없는 노드라면 함수 리턴
    if (node == -1) 
        return;

    // 순회 횟수 증가
    cnt++;

    // 루트 기준 좌측 노드 순회, flag = false
    travel(tree[node].first, false);

    //우측 노드에 도달했다면 우순회 횟수 증가
    if (flag == true) // 루트 기준 우측 트리
    {
        //우측트리 중 우측 노드 방문 횟수 카운트
        Rcnt++;
        travel(tree[node].second, true);
    }
    else // 루트 기준 좌측 트리 중 우측 노드 방문
    {
        travel(tree[node].second, false);
    }
}

int main() 
{
    input();
    travel(1, 1);
    cout <<  2 * cnt - Rcnt;
}