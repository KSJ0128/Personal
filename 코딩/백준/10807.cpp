#include <iostream>
using namespace std;
int main()
{
    int N, num[100], target, count = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    cin >> target;

    for(int i = 0; i < N; i++)
    {
        if(target == num[i])
            count++;
    }

    cout << count;
}