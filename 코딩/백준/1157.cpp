#include <iostream>
#include <string>
using namespace std;

// int a[26] 초기화 안해주면 틀림. 초기화 제발;;
int main()
{
    string s; cin >> s; // 문자열 입력 받기
    int a[26] = {0,}; // 문자열에 쓰이는 알파벳 횟수 저장
    
    for(int i = 0; i < s.length(); i++) // 알파벳별 사용 횟수 파악
    {
        int j = s.at(i) - 65;

        if(j < 26) // 대문자일 때
        {
            if(a[j] == 0)
                a[j] = 1;
            else
                a[j]++;
        }
        else // 소문자일 때
        {
            j -= 32;

            if(a[j] == 0)
                a[j] = 1;
            else
                a[j]++;
        }
    }
    
    int max = a[0];
    char maxA = 'A';

    for(int i = 1; i < 26; i++) 
    {
        if(a[i] > max)
        {
            maxA = 'A' + i;
            max = a[i];
        }    
        else if(a[i] == max)
        {
            maxA = '?';
        }
    }

    cout << maxA;   
}