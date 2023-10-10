#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N; cin >> N; // 단어의 개수 입력 받기
    int result = N; // 그룹 단어 개수

    for(int i = 0; i < N; i++) // 단어 개수 만큼 반복
    {
        string s; cin >> s; // 단어 입력 받기
        int a[26] = {0,}; // 알파벳 출현 여부 체크
        a[s.at(0)-97] = 1; // 첫번째 알파벳 체크

        for(int j = 1; j < s.length(); j++) // 단어의 길이 만큼 반복
        {
            if(s.at(j-1) - 97 == s.at(j) - 97)// i, i-1번째의 알파벳이 같은 경우
                continue; // 다음 인덱스로 점프
            else // i, i-1번째의 알파벳이 다른 경우
            {
                if(a[s.at(j) - 97] == 0) // 알파벳이 나오지 않은 경우
                    a[s.at(j) - 97] = 1; // 알파벳 출현 체크
                else // 알파벳이 나온 경우
                {
                    result -= 1;
                    break; // 현재 반복문 탈출
                }    
            }
        }
    }

    cout << result;
}