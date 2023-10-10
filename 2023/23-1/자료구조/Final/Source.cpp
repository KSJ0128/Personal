#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define MAX_PEOPLE 891
#define INF 100000000
#define MAX_VERTEX 893

using namespace std;

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
        names_ = new string[num_rows];
        survived_ = new bool[num_rows];
        pclasses_ = new int[num_rows];
        sexes_ = new string[num_rows];
        fares_ = new double[num_rows];
        dist_to_toffi_ = new int[num_rows];
        speed_ = new int[num_rows];

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
                else if (j == 1) {
                    //survived_[i] = stoi(cell);
                    names_[i] = cell;
                }
                else if (j == 2) {
                    //pclasses_[i] = stoi(cell);
                    survived_[i] = stoi(cell);
                }
                else if (j == 3) {
                    //sexes_[i] = cell;
                    pclasses_[i] = stoi(cell);
                }
                else if (j == 4) {
                    //fares_[i] = stod(cell);
                    sexes_[i] = cell;
                }
                else if(j == 5) {
                    // ticket price
                    fares_[i] = stod(cell);
                }
                else if (j == 6) {
                    dist_to_toffi_[i] = stod(cell);
                }
                else if (j == 7) {
                    speed_[i] = stod(cell);
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
            cout << nums_[i] << "," << names_[i] << "," << survived_[i] << "," << pclasses_[i] << "," << sexes_[i] << "," << fares_[i] << "," << dist_to_toffi_[i] << "," << speed_[i] << endl;
        }
    }

    ~TitanicData() {
        delete[] nums_;
        delete[] names_;
        delete[] survived_;
        delete[] pclasses_;
        delete[] sexes_;
        delete[] fares_;
        delete[] dist_to_toffi_;
        delete[] speed_;
    }

    double getFares(int i) {
        return fares_[i];
    }

    int getPclasses(int i) {
        return pclasses_[i];
    }

    string getSexes(int i) {
        return sexes_[i];
    }

    void roseAndJack(int& rose, int& jack) {
        for(int i = 0; i < MAX_PEOPLE; i++) {
            if(names_[i] == "Rose")
                rose = i+1; 
            if(names_[i] == "Jack" && sexes_[i] == "male")
                jack = i+1; 
        }
    }

private:
    int* nums_;
    string* names_;
    bool* survived_;
    int* pclasses_;
    string* sexes_;
    double* fares_;
    int* dist_to_toffi_;
    int* speed_;
    int num_rows_;
};

class TicketPrice {
    int front;
    int rear;
    double que[891];
    double voucher[891] = {0.0};

    public:
    TicketPrice()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(double fare, int pClass) // 2등석 승객만 큐에 삽입
    {
        if(pClass == 2)
            que[++rear] = fare;
    }

    double dequeue()
    {
        return que[++front];
    }

    void set(TitanicData& titanic) {
        for(int i = 0; i < MAX_PEOPLE; i++)
            enqueue(titanic.getFares(i), titanic.getPclasses(i));
        check();
        print();
    }

    void check()
    {
        for(int i = 0; i <= rear; i++)
        {
            double fare = dequeue(); // pop된 ticket price

            for(int j = front + 1; j <= rear; j++)
            {
                if(fare >= que[j]) // 뒤의 티켓가가 더 작은 경우 해당 티켓가 * 0.1 = 바우처
                {
                    voucher[i] = que[j] * 0.1;
                    break;
                }
            }
        }
    }

    void print()
    {
        for(int i = 0; i <= rear; i++)
        {
            if(i == 0)
                cout << "Voucher for Second-Class Passengers: [" << voucher[0] << ", ";
            else if(i == rear)
                cout << voucher[rear] << "]" << endl;
            else
                cout << voucher[i] << ", ";
        }
    }
};

class HeapNode {
    pair<int, int> edge; // w, v

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

class MinHeap {
    HeapNode vertexes[MAX_VERTEX];
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
        return size == MAX_VERTEX - 1;
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

    HeapNode find() // 우선 순위 가장 높은 요소(가중치 가장 낮은) 리턴
    {
        return vertexes[1];
    }
};

class SaveJack {
    MinHeap pq;
    int dist[MAX_VERTEX];
    int roseToJack, jackToBoat;

    public:
    SaveJack() {
        fill(dist, dist+MAX_VERTEX, INF);
        roseToJack = jackToBoat = 0;
    }

    void dijkstra(int start, vector<pair<int,int>> nodes[]) {
        pq.insert(0, start);
        dist[start] = 0;

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

    void calculateDist(int rose, int jack, int boat, vector<pair<int,int>> nodes[]) {
        dijkstra(rose, nodes);
        int roseToJack = dist[jack];

        dijkstra(jack, nodes);
        int jackToBoat = dist[boat];

        if(roseToJack + jackToBoat + 10 > 100)
            cout << "Rose와 Jack은 탈출이 불가능합니다" << endl;
        else
            cout << "Rose와 Jack은 탈출이 가능합니다" << endl;
    }
};

class CheckSurvivalRate {
    MinHeap pq;
    int dist[MAX_VERTEX];
    pair<int,int> sortedDist[MAX_VERTEX];
    pair<int,int> zero;
    double survivalRate;

    public:
    CheckSurvivalRate() {
        zero = {0,0};
        survivalRate = 1.0;
        fill(dist, dist+MAX_VERTEX, INF);
        fill(sortedDist, sortedDist+MAX_VERTEX, zero);
    }

    void dijkstra(int start, vector<pair<int,int>> nodes[]) {
        pq.insert(0, start);
        dist[start] = 0;

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

    int tupleSort(TitanicData& titanic)
    {
        int surviveMen = 0;

        for(int i = 1; i < MAX_VERTEX; i++) // tuple 초기화
        {
            sortedDist[i].first = dist[i];
            sortedDist[i].second = i;
        }

        sort(sortedDist, sortedDist+MAX_VERTEX);

        for(int j = 1; j < MAX_VERTEX; j++)
        {
            if(titanic.getSexes(sortedDist[j].second) == "male" && titanic.getPclasses(sortedDist[j].second) == 1)
                surviveMen++;
        }

        return surviveMen;
    }

    void calculateRate(int start, vector<pair<int,int>> nodes[], TitanicData& titanic) {
        dijkstra(start, nodes);
        survivalRate *= tupleSort(titanic) * survivalRate / 600;

        cout << "Survival Rate of First-Class Male Passengers: " << survivalRate;
    }
};

int main()
{
    TitanicData titanic;
    titanic.read_data("titanic.csv");

    // Ticket Price
    TicketPrice price;
    price.set(titanic);

    // 3~5번 문제 
    int v, e, index, ver, weight;
    vector<pair<int,int>> nodes[MAX_VERTEX];

    ifstream inputFile("test.dat");
    inputFile >> v >> e;

    // 그래프 초기화
    for(int i = 0; i < e; i++) { 
        inputFile >> index >> ver >> weight;
        nodes[index].push_back(make_pair(weight,ver));
    }

    inputFile.close();

    // Save Jack
    SaveJack save;
    int rose, jack, boat = 892;
    titanic.roseAndJack(rose, jack);
    save.calculateDist(rose, jack, boat, nodes); // 45, 46

    // Check Survival Rate
    CheckSurvivalRate survive;
    survive.calculateRate(boat, nodes, titanic);
}