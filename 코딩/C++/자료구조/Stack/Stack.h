#ifndef STACK
#define STACK
const int MAX_SIZE = 20;

class stack
{
    private:
    int top;
    int array[MAX_SIZE];

    public:
    stack();
    ~stack();
    void push(int x);
    int pop();
    bool isEmpty();
    int peek();
    bool isFull();
    int size();
    void display();
};

#endif