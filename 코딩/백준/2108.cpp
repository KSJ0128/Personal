#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int calcMode(vector<int>& num, int N)
{
    vector< vector<int> > mode;
    vector<int> minimum;
    int cnt = 1, max = 0;
    for(int i = 0; i < N; i++)
    {
        if(i == N-1)
        {
            if(num[i] == num[i-1])
                mode.push_back(vector<int>(cnt, num[i]));
            else
                mode.push_back(vector<int>(1, num[i]));
            if(cnt > max)
                max = cnt;
        }
        else if(num[i] != num[i+1])
        {
            mode.push_back(vector<int>(cnt, num[i]));
            if(cnt > max)
                max = cnt;
            cnt = 1;
        }
        else
            cnt++;
    }

    for(int i = 0; i < mode.size(); i++)
    {
        if(mode[i][0] == max)
            minimum.push_back(mode[i][1]);
    }
    sort(minimum.begin(), minimum.end());
    return minimum[1];
}

int main()
{
    int N, mean = 0, medium = 0, mode = 0, range = 0;
    vector<int> num;
    cin >> N;
    num.resize(N);

    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    sort(num.begin(), num.end());
    mean = accumulate(num.begin(), num.end(), 0) / num.size();
    medium = num[num.size() / 2];
    mode = calcMode(num, N);
    range = num[N-1] - num[0];

    cout << mean << '\n' << medium << '\n' << mode << '\n' << range;
}