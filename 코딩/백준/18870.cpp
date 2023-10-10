#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nRank;
vector<int> arr;

int binSrch(int num)
{
    int left = 0, right = nRank.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(num == nRank[mid])
            return mid;
        else if(num < nRank[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
        nRank.push_back(num);
    }

    sort(nRank.begin(), nRank.end());
    nRank.erase(unique(nRank.begin(), nRank.end()), nRank.end());
    
    for(int i = 0; i < N; i++)
        cout << binSrch(arr[i]) << '\n';
}

/*
bool compare1(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

bool compare2(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, rank = 0;
    vector< vector<int> > arr;
    cin >> N;
    arr.resize(N);

    for(int i = 0; i < N; i++)
    {
        arr[i].resize(3);
        cin >> arr[i][0];
        arr[i][1] = i;
    }

    sort(arr.begin(), arr.end(), compare1);
    arr[0][2] = 0;

    for(int i = 1; i < N; i++)
    {
        if(arr[i][0] == arr[i-1][0])
            arr[i][2] = arr[i-1][2];
        else
            arr[i][2] = arr[i-1][2] + 1;
    }

    sort(arr.begin(), arr.end(), compare2);

    for(int i = 0; i < N; i++)
        cout << arr[i][2] << '\n';
}
*/