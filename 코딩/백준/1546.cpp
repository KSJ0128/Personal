#include <iostream>
using namespace std;
int main()
{
    int N, score, max = 0;
    double aver = 0; // 시험 본 과목의 수
    cin >> N;

    for(int i = 0; i < N; i++)
    {   
        cin >> score;
        aver += score;

        if(i == 0)
            max = score;
        
        if(score > max)
            max = score;
    } // max 구하기

    aver = aver / N / max * 100;
    cout << aver;
}