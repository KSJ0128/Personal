#include <iostream>
#include <queue>
using namespace std;
const int SIZE = 5000;
int main()
{
    queue<int> q;
    int josephus[SIZE];
    int top = 0, n, k;
    cin >> n >> k; 
    
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        for(int i = 0; i < k-1; i++)
        {   
            q.push(q.front());
            q.pop(); 
        }
        josephus[top++] = q.front();
        q.pop();
    }

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            if(n == 1) // 숫자가 한 개인 경우
                cout << "<" << josephus[0] << ">";
            else // 숫자가 두 개 이상인 경우
                cout << "<" << josephus[i] << ", ";
        }
        else if(i == n-1)
            cout << josephus[i] << ">";
        else 
            cout << josephus[i] << ", ";
    }
}