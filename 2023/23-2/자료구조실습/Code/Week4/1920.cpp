#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int N, M, data;
    vector<int> arr;
    
    cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> data;
        bool check = binary_search(arr.begin(), arr.end(), data);
        if(check)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}