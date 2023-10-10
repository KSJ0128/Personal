#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,x,y;
    vector<pair<int, int>> XY;
    vector<pair<int, int>>::iterator iter;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        XY.push_back({x,y});
    }

    sort(XY.begin(), XY.end(), compare);

    for(iter = XY.begin(); iter!=XY.end(); iter++){
		cout << iter->first << " " << iter->second << '\n';
	}
}