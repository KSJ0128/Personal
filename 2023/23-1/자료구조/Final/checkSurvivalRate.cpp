#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define INF 100000000
#define MAX_V 893

vector<pair<int,int>> nodes[MAX_V];
int dist[MAX_V];
pair<int, int> t [MAX_V];
pair<int,int> stn= {1,2};

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

class TitanicData {
public:
    TitanicData() {}

    void read_data(string file_path) {
        ifstream input_file(file_path);
        if (!input_file.is_open()) {
            cerr << "Failed to open input file" << endl;
            return;
        }

        // Count number of data rows
        int num_rows = 0;
        string line;
        while (getline(input_file, line)) {
            num_rows++;
        }
        input_file.clear();
        input_file.seekg(0, ios::beg);

        // Allocate memory for data arrays
        nums_ = new int[num_rows];
        pclasses_ = new int[num_rows];
        sexes_ = new string[num_rows];

        // Read data rows and store in arrays
        int i = 0;
        while (getline(input_file, line)) {
            stringstream ss(line);
            string cell;
            int j = 0;
            while (getline(ss, cell, ',')) {
                if (j == 0) {
                    nums_[i] = stoi(cell);
                }
                else if (j == 3) {
                    //sexes_[i] = cell;
                    pclasses_[i] = stoi(cell);
                }
                else if (j == 4) {
                    //fares_[i] = stod(cell);
                    sexes_[i] = cell;
                }
                j++;
            }
            i++;
        }

        input_file.close();
        num_rows_ = num_rows;
    }

    void print_data() {
        for (int i = 0; i < num_rows_; i++) {
            cout << nums_[i] << "," << pclasses_[i] << "," << sexes_[i] << endl;
        }
    }
    
    int getPclass(int i)
    {
        return pclasses_[i];
    }

    string getSex(int i)
    {
        return sexes_[i];
    }

    int getNum(int i)
    {
        return nums_[i];
    }

    int countWomen(int firstSecondWomen, TitanicData data)
    {
        for(int i = 0; i < num_rows_; i++)
        {
            if(data.getSex(i) == "female" && (data.getPclass(i) == 1 || data.getPclass(i) == 3))
                firstSecondWomen += 1;
        }

        return firstSecondWomen;
    }

private:
    int* nums_;
    int* pclasses_;
    string* sexes_;
    int num_rows_;
};

int tupleSort(int dist[], pair<int,int> t[], TitanicData data)
{
    int surviveMen = 0;

    for(int i = 1; i < MAX_V; i++) // tuple 초기화
    {
        t[i].first = dist[i];
        t[i].second = i;
    }

    sort(t, t+MAX_V);

    for(int j = 1; j < MAX_V; j++)
    {
        if(data.getSex(t[j].second) == "male" && data.getPclass(t[j].second) == 1)
            surviveMen++;
    }

    return surviveMen;
}

int main()
{
    TitanicData data;
    data.read_data("titanic.csv");
    int lifeBoatCrew = 600, firstSecondWomen = 0, remainNum; // fSW = 138, remain = 362
    double surviveRate = 1.0;
    remainNum = lifeBoatCrew - data.countWomen(firstSecondWomen, data);

    fill(dist, dist+MAX_V, INF);
    fill(t,t+MAX_V,stn);

    int v, e, index, ver, weight;
    ifstream inputFile("test.dat");

    inputFile >> v >> e;

    for(int i = 0; i < e; i++) { // 그래프 초기화
        inputFile >> index >> ver >> weight;
        nodes[index].push_back(make_pair(weight,ver));
    }

    inputFile.close();

    dijkstra(892);

    surviveRate *= tupleSort(dist, t, data) / surviveRate / 600;

    cout << surviveRate;
}