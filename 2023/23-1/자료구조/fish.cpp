#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int N, num, sum = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;

        if(i == 0)
            s.push(num);
        else if(s.top() > num)
        {
            sum += 1 * (s.top() - num);
        }
        else if(s.top() < num)
        {
            s.pop();
            s.push(num);
        }
        else
            continue;
    }
}

