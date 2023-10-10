#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100001;

class Sequence
{
    private:
    int top;
    bool stack[SIZE];
    string plusMinus;

    public:
    Sequence()
    {
        top = 0;
        plusMinus = "";
    }

    void push()
    {
        top++;
        plusMinus += "+";
    }

    void pop()
    {
        stack[top--] = true;
        plusMinus += "-";
    }

    void check(int* c, int size)
    {
        for(int k = 0; k < size; k++)
        {
            if(top < c[k]) // Case : push
            {
                for(int i = top; i < c[k]; i++)
                {
                    if(stack[top+1] == false)
                        push();
                    else
                        top++;
                }
                pop();
            }
            else // Case : pop
            {
                for(int i = top; i >= c[k]; i--)
                {
                    if(stack[top] == false)
                    {
                        if(c[k] == top)
                            pop();
                        else
                        {
                            cout << "NO";
                            exit(0);
                        }
                    }
                    else
                        top--;
                }
            }
        }
    }

    void display()
    {
        for(int i = 0; i < plusMinus.length(); i++)
            cout << plusMinus[i] << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  

    int n;
    cin >> n;

    int c[SIZE] = {};

    for(int i = 0; i < n; i++)
        cin >> c[i];

    Sequence seq; // 수열 세팅   
    seq.check(c, n);
    seq.display();
}