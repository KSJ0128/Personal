#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // 시간 절약
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int stickCount = 0, laserCount = 0; // 쇠막대기의 개수, 레이저의 개수
    stack<char> s; // 괄호 저장하는 스택
    stack<int> laser; // 레이저 보류할 때 사용하는 스택

    string str = ""; // 쇠막대기와 레이저 배치 나타내는 문자열
    cin >> str; // 문자열 입력

    for(int i = 0; i < str.size(); i++) // 괄호 문자열의 길이만큼 반복
    {
        if(str[i] == '(') // i번째 문자가 (인 경우
        {
            s.push('('); // 괄호 스택에 ( push

            if(str[i-1] == '(') // (가 연속으로 나온 경우 새로운 쇠막대기가 나왔다는 의미이므로 이전에 나왔던 레이저를 초기화 한다.
            {
                // i-1번째 문자가 (인 경우 레이저 개수 초기화 해준다
                laser.push(laserCount);
                laserCount = 0;
            }
        }
        else // i번째 문자가 )인 경우
        {
            s.pop(); // 괄호 스택에 들어있는 (를 pop해준다.

            if(str[i-1] == '(') // i-1번째 문자 즉, 직전 문자가 (인 경우 == laser
            {
                laserCount++; // laser 개수 증가

                if(s.empty()) // 스택에 있던 (를 pop하고 괄호 스택이 비어있는 경우, 쇠막대기와 관련 없는 레이저라는 의미.
                    laserCount = 0; // 레이저 개수 초기화
            }
            else // i-1번째 문자 즉, 직전 문자가 )인 경우 == stick, 쇠막대기의 끝을 나타냄
            {
                stickCount += laserCount + 1; // stick의 개수를 초기화 해준다. laser 개수 + 1을 더해줌.

                if(s.empty()) // 스택에 있던 (를 pop하고 괄호 스택이 비어있는 경우, 중첩된 쇠막대기가 없다는 뜻
                {
                    laserCount = 0; // 레이저 개수 초기화
                }
                else // 괄호 스택이 비어있지 않음 == 중첩된 쇠막대기가 존재
                {
                    if(!laser.empty()) // 보류한 laser가 있는 경우 개수를 복원해준다.
                    {
                        laserCount += laser.top();
                        laser.pop();
                    }
                }
            }
        }
    }
    cout << stickCount;
}