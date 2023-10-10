#include <iostream>
using namespace std;

int inputScore(int score[], int index) // 점수 입력 받기
{
    int currentScore = 0;

    for(int i = 0; i < 101; i++)
    {
        cin >> currentScore;
        
        if(currentScore < 0)
        {
            index = i;
            break;
        }
            
        score[i] = currentScore;
    }

    return index;
}

void scoreAnalysis(int score[], int index)
{
    double average;
    int sum = 0, less = 0, more = 0;

    for(int i = 0; i < index; i++)
    {
        sum += score[i];
    }

    average = sum / (index-1);

    for(int i = 0; i < index; i++)
    {
        if(score[i] >= average)
            more++;
        else
            less++;
    }

    cout << "평균과 같거나 큰 점수의 개수는 " << more << "개고, 평균보다 작은 점수의 개수는  "<< less << "개입니다.";
}

int main()
{
    int score[101], scoreIndex;
    scoreIndex = inputScore(score, scoreIndex);
    scoreAnalysis(score, scoreIndex);
}