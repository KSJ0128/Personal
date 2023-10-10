#include <iostream>
using namespace std;

class Node
{
    int distance;
    int speed;
    Node* next;

    public:
    Node(int d, int s)
    {
        distance = d;
        speed = s;
        next = NULL;
    }

    Node* getLink()
    {
        return next;
    }

    void setLink(Node* n)
    {
        next = n;
    }

    bool hasDistance(int d)
    {
        return distance == d;
    }

    int getSpeed()
    {
        return speed;
    }

    void insertNext(Node* n)
    {
        if(n != NULL)
            next = n;
    }
};

class LinkedList
{
    Node org;

    public:
    LinkedList(): org(0,0) {}

    Node* getHead()
    {
        return org.getLink();
    }

    bool isEmpty()
    {
        return getHead() == NULL;
    }
};

int main()
{
    int numOfPartners = 0, minSpeed = 0;
    bool check = false;
    LinkedList list;

    int distance_toffi[2, 4, 10, 5, 7];
    int speed_toffi[2, 4, 1, 1, 3];
}

// Input: distance_to_toffi_ = [2, 4, 10, 5, 7], speed = [2, 4, 1, 1, 3]
// Output: 3

// Input: distance_to_toffi_ = [20, 18, 16], speed_ = [4, 2, 1]
// Output: 1