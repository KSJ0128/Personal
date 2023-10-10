#include <iostream>
using namespace std;

class Node
{
    private:
    int data;
    Node* link;

    public:
    Node(int value)
    {
        data = value;
        link = NULL;
    }

    int getData()
    {
        return data;
    }

    Node* getLink()
    {
        return link;
    }
    
    void setLink(Node* next)
    {
        link = next;
    }

    void display()
    {
        cout << data << " ";
    }

    bool hasData(int value)
    {
        return data == value;
    }

    void insertNext(Node* n)
    {
        if(n != NULL)
            n -> link = link;
        link = n;
    }

    Node* removeNext() 
    {
        Node* removed = link; // return 하기 위해서
        if(removed != NULL)
            link = removed -> link;
        return removed;
    }
};

class LinkedList
{
    private:
    Node org; // Head Node

    public:
   	LinkedList(): org(0) { }	

    ~LinkedList()
    {
        clear();
    }

    Node* getHead()
    {
        return org.getLink();
    }

    bool isEmpty()
    {
        return getHead() == NULL;
    } // Head 노드의 링크가 null이면 연결 리스트가 비어있다는 뜻 

    void clear()
    {
        while(!isEmpty())
            delete remove(0);
    }

    void insert(int pos, Node* n)
    {
        Node* prev = getEntry(pos-1);
        if(prev != NULL)
            prev -> insertNext(n);
    }

    Node* remove(int pos)
    {
        Node* prev = getEntry(pos-1);
        return prev -> removeNext();
    }

    Node* getEntry(int pos)
    {
        Node* n = &org;
        for(int i = -1; i < pos; i++, n = n -> getLink())
        {
            if(n == NULL)
                break;
        }
        return n;
    }

    Node* find(int item)
    {
        for(Node* p = getHead(); p!= NULL; p = p -> getLink())
        {
            if(p -> hasData(item))
                return p;
        }
        return NULL;
    }

    void replace(int pos, Node* n)
    {
        Node* prev = getEntry(pos - 1);
        if(prev != NULL)
        {
            delete prev -> removeNext();
            prev -> insertNext(n);
        }
    }

    int size() 
    {
        int count = 0;
        for(Node* p = getHead(); p != NULL; p = p -> getLink())
            count++;
        return count;
    }

    void display()
    {
        cout << "[전체 항목 수 = " << size() << " ] : ";
        for(Node* p = getHead(); p != NULL; p = p -> getLink())
            p -> display();
        cout << endl;
    }

    void sumData()
    {
        int sum = 0;

        for(Node* p = getHead(); p != NULL; p = p -> getLink())
            sum += p->getData();

        cout << "데이터의 합: " << sum << endl;
    }

    void countNode(int data)
    {
        int count = 0;

        for(Node* p = getHead(); p != NULL; p = p -> getLink())
        {
            if(p->hasData(data))
                count++;
        }
        cout << "해당 데이터를 가지는 노드의 개수: " << count << endl;
    }
};



int main()
{
    LinkedList list;
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(list.size(), new Node(10));
    list.insert(2, new Node(50));
    list.display();
    list.sumData();
    list.countNode(10);
    list.remove(2);
    list.remove(list.size()-1);
    list.remove(0);
    list.replace(1, new Node(90));
    list.display();
    list.sumData();
    list.clear();
    list.display();
}