#include <iostream>
#include <fstream>
#define MAX_VTXS 256
#define MAX_QUEUE_SIZE 100
using namespace std;

class CircularQueue {
    protected:
        int front;
        int rear;
        int data[MAX_QUEUE_SIZE];

    public:
        CircularQueue() {front = rear = 0;}
        
        bool isEmpty() {return front == rear;}
        bool isFull() {return (rear+1) % MAX_QUEUE_SIZE == front;}

        void enqueue(int val) {
            if(!isFull()) {
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        int dequeue() {
            if(!isEmpty()) {
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
        int peek() {
            if(!isEmpty())
                return data[(front+1) % MAX_QUEUE_SIZE];
        }
        void display() {
            cout << "큐 내용: ";
            int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
            for(int i = front + 1; i <= maxi; i++)
                cout << data[i % MAX_QUEUE_SIZE];
        }
};

class AdjMatGraph {
    protected: 
        int size;
        char vertices[MAX_VTXS];
        int adj[MAX_VTXS][MAX_VTXS];
    public:
        AdjMatGraph() {reset();}
        
        void reset() {
            size = 0;
            for(int i = 0; i < MAX_VTXS; i++) {
                for(int j = 0; j < MAX_VTXS; j++) 
                    setEdge(i,j,0);
            }
        }

        bool isEmpty() {return size == 0;}
        bool isFull() {return size >= MAX_VTXS;}

        char getVertex(int i) {return vertices[i];}
        int getEdge(int i, int j) {return adj[i][j];}
        void setEdge(int i, int j, int val) {adj[i][j] = val;}

        void insertVertex(char name) {
            if(!isFull()) 
                vertices[size++] = name;
            else 
                cout << "Error: 그래프 정점 개수 초과" << endl;
        }

        void insertEdge(int u, int v) {
            setEdge(u,v,1);
            setEdge(v,u,1);
        }

        void display() {
            cout << size << endl;
            for(int i = 0; i < size; i++) {
                cout << getVertex(i);
                
                for(int j = 0; j < size; j++)
                    cout << "   " << getEdge(i,j);
                cout << endl;
            }
        }
};

class SrchAMGraph : public AdjMatGraph {
    bool visited[MAX_VTXS];

    public: 
        void resetVisited() {
            for(int i = 0; i < size; i++)
                visited[i] = false;
        }

        bool isLinked(int u, int v) {return getEdge(u,v) != 0;}

        void BFS(int v) {
            visited[v] = true;
            cout << getVertex(v);

            CircularQueue que;
            que.enqueue(v);

            while(!que.isEmpty()) {
                int v = que.dequeue();
                for(int w = 0; w < size; w++) {
                    if(isLinked(v,w) && visited[w] == false) {
                        visited[w] = true;
                        cout << " " << getVertex(w);
                        que.enqueue(w);
                    }
                }
            }
        }
};

int main()
{
    int num, val;
    char vName;
    SrchAMGraph g;
    ifstream inputFile("test.dat");

    inputFile >> num;

    for(int i = 0; i < num; i++) {
        inputFile >> vName;
        g.insertVertex(vName);

        for(int j = 0; j < num; j++) {
            inputFile >> val;
            if(val != 0)
                g.insertEdge(i,j);
        }
    }
    inputFile.close();

    g.display();
    cout << "BFS ==> ";
    g.resetVisited();
    g.BFS(0);
}