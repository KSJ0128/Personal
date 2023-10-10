#include <iostream>
#include <ctime> // time(0)이라는 현재 시간에 대한 초값을 불러오는 함수 포함.
using namespace std;

int main()
{
    
    int totalSeconds = time(0);

    cout<< totalSeconds;
    int currentSeconds = totalSeconds % 60;

    int totalMinutes = totalSeconds / 60;
    int currentMinutes = totalMinutes % 60;

    int totalHours = totalMinutes / 60;
    int currentHours = totalHours % 24;

    cout << currentHours << "시 " << currentMinutes << "분 " << currentSeconds << "초" << endl;
    // 오류 아님. 그리니치 천문대 기준이라 시차 9시간.
}