#include <iostream>
#include <queue>
using namespace std;
#define MAX_ELEMENT 200

class HeapNode
{
    int key;

    public:
    HeapNode(int k = 0)
    {
        key = k;
    }

    void setKey(int k)
    {
        key = k;
    }

    int getKey()
    {
        return key;
    }

    void display()
    {
        cout << key;
    }
};

class MinHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;

    public:
    MinHeap()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == MAX_ELEMENT - 1;
    }

    HeapNode& getParent(int i)
    {
        return node[i/2];
    }

    HeapNode& getLeft(int i)
    {
        return node[i*2];
    }

    HeapNode& getRight(int i)
    {
        return node[i*2 + 1];
    }

    void insert(int key)
    {
        if(isFull())
            return;

        int i = ++size;
        node[i] = key;

        while(i != 1 && key < getParent(i).getKey()) // 루트 아니고, 부모 노드보다 키 값이 작으면
        {
            node[i] = getParent(i); // 부모 노드 끌어내림
            i /= 2; // 한 레벨 위로 상승
        }

        node[i].setKey(key); // 부모 레벨에 키 삽입
    }

    HeapNode remove()
    {
        if(isEmpty())
            return NULL;
        
        HeapNode item = node[1]; // 루트 노드(리턴)
        HeapNode last = node[size--]; // 힙의 말단 노드
        int parent = 1, child = 2; // 루트의 왼쪽 자식

        while(child <= size) // 힙 트리 벗어나지 않는 동안
        {
            if(child < size && 
                getLeft(parent).getKey() > getRight(parent).getKey()) // 동레벨에서 더 작은 자식 노드로 이동
            {
                child++;
            }
            
            if(last.getKey() <= node[child].getKey()) // 마지막 노드가 자식 노드보다 작으면
            {
                break;
            }

            // 아닌 경우 한 단계 아래 레벨로 이동
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }

        node[parent] = last; // 마지막 노드를 최종 위치에 저장
        return item;
    }

    HeapNode find() // 우선 순위 가장 낮은 요소 리턴
    {
        return node[1];
    }

    void display()
    {
        for(int i = 1, level = 1; i <= size; i++)
        {
            if(i == level)
            {
                cout << endl;
                level *= 2;
            }

            node[i].display();
        }
        cout << endl;
    }
};

int main()
{}