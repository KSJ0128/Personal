#include <iostream>
using namespace std;
int main()
{
    int N, max, min;
    int num[1000000] = {0,};
    cin >> N; // 1 ~ 1,000,000

    cin >> num[0];
    max = num[0];
    min = num[0];

    for(int i = 1; i < N; i++)
    {
        cin >> num[i];
        
        if(num[i] > max)
            max = num[i];
        
        if(num[i] < min)
            min = num[i];
    }

    cout << min << " " << max;
}