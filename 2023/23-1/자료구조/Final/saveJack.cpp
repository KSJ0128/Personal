#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define INF 100000000
#define MAX_V 893

vector<pair<int,int>> nodes[MAX_V];
int dist[MAX_V];

class HeapNode
{
    pair<int, int> edge;

    public:
    HeapNode()
    {
        edge = make_pair(0,0);
    }

    HeapNode(int w, int v)
    {
       edge = make_pair(w,v);
    }

    int getWeight()
    {
        return edge.first;
    }

    int getVer()
    {
        return edge.second;
    }

    void setWeight(int w)
    {
        edge.first = w;
    }
    
    void setVer(int v)
    {
        edge.second = v;
    }
};

class MinHeap
{
    HeapNode vertexes[MAX_V];
    int size;

    public:
    MinHeap(): vertexes{} {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == MAX_V - 1;
    }

    HeapNode& getParent(int i)
    {
        return vertexes[i/2];
    }

    HeapNode& getLeft(int i)
    {
        return vertexes[i*2];
    }

    HeapNode& getRight(int i)
    {
        return vertexes[i*2 + 1];
    }

    void insert(int w, int v)
    {
        if(isFull())
            return;

        int i = ++size;
        vertexes[i] = HeapNode(w,v);

        while(i != 1 && w < getParent(i).getWeight()) // 루트 아니고, 부모 노드보다 키 값이 작으면
        {
            vertexes[i] = getParent(i); // 부모 노드 끌어내림
            i /= 2; // 한 레벨 위로 상승
        }

        vertexes[i].setWeight(w);
        vertexes[i].setVer(v);
    }

    HeapNode remove()
    {
        HeapNode item = vertexes[1]; // 루트 노드(리턴)
        HeapNode last = vertexes[size--]; // 힙의 말단 노드
        int parent = 1, child = 2; // 루트의 왼쪽 자식

        while(child <= size) // 힙 트리 벗어나지 않는 동안
        {
            if(child < size && 
                getLeft(parent).getWeight() > getRight(parent).getWeight()) // 동레벨에서 더 작은 자식 노드로 이동
            {
                child++;
            }
            
            if(last.getWeight() <= vertexes[child].getWeight()) // 마지막 노드가 자식 노드보다 작으면
            {
                break;
            }

            // 아닌 경우 한 단계 아래 레벨로 이동
            vertexes[parent] = vertexes[child];
            parent = child;
            child *= 2;
        }

        vertexes[parent] = last; // 마지막 노드를 최종 위치에 저장
        return item;
    }

    HeapNode find() // 우선 순위 가장 낮은 요소 리턴
    {
        return vertexes[1];
    }
};

void dijkstra(int start) {
    MinHeap pq;
    dist[start] = 0;
    pq.insert(0, start); // w, v

    while(!pq.isEmpty()) {
        HeapNode current = pq.find();
        int cost = current.getWeight();
        int here = current.getVer();
        pq.remove();

        if(dist[here] < cost) 
            continue;

        for(int i = 0; i < nodes[here].size(); i++) {
            int via_cost = cost + nodes[here][i].first;

            if(via_cost < dist[nodes[here][i].second]) {
                dist[nodes[here][i].second] = via_cost;
                pq.insert(via_cost, nodes[here][i].second);
            }
        }
    }
}

int main()
{
    fill(dist, dist+MAX_V, INF);

    int v, e, index, ver, weight;
    ifstream inputFile("test.dat");

    inputFile >> v >> e;

    for(int i = 0; i < e; i++) { // 그래프 초기화
        inputFile >> index >> ver >> weight;
        nodes[index].push_back(make_pair(weight,ver));
    }

    inputFile.close();

    dijkstra(830);
    int roseToJack = dist[123];

    dijkstra(123);
    int jackToBoat = dist[892];

    if(roseToJack + jackToBoat + 10 > 100)
        cout << "탈출 불가" << endl;
    else
        cout << "탈출 가능" << endl;

    cout << roseToJack << " " << jackToBoat;
}