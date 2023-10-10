#include <iostream>
#include <stack>
#include <string>
using namespace std;

// getline(cin,S): 공백 포함 문자열 입력 받기
int main()
{
    // 실행 속도 높여주는 코드
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> s;
    string S; // 문자열

    getline(cin,S); // 공백 포함해 문자열 입력

    for(int i = 0; i < S.size(); i++) // 입력 받은 문자열의 길이 만큼 반복
    {
        // 태그 출력하는 경우, <> 사이의 내용은 그대로 출력
        if(S[i] == '<') // 문자열의 i번째 문자가 <인 경우
        {
            while(S[i] != '>') // 문자열의 i번째 문자가 >가 될 때까지 문자를 출력
                cout << S[i++];
            cout << S[i]; // 문자 > 출력
        }
        else // 문자열의 i번째 문자가 <인 경우 
        {
            // 단어, 공백 출력
            while(i < S.size()) // 인덱스 i가 문자열의 크기보다 작으면 계속 반복
            {
                if(S[i] == '<') // i번째 문자가 <인 경우, 태그가 나온 경우
                {
                    i--; // loop가 한 번 끝나면 i++을 실행하므로 i--를 해주지 않으면 문자 <를 건너뛰게 된다.
                    break; // 인덱스를 하나 줄이고 while 반복문을 탈출
                }
                else if(S[i] == ' ') // i번째 문자가 공백인 경우, 공백이 나온 경우
                    break; // while 반복문 탈출
                // while은 loop가 끝나도 인덱스를 키워주는 코드가 없어 i++ 코드 추가.
                s.push(S[i++]); // 태그나 공백을 마주치지 않은 경우 스택에 i번째 문자를 삽입하고, 인덱스를 하나 키운다
            }
            
            // 단어가 끝났을 때
            while(!s.empty()) // 스택을 pop해 단어 출력
            {
                cout << s.top();
                s.pop();
            }
            
            // 공백을 마주했을 때 push, 인덱스 조정 등의 처리를 해주지 않아 공백 출력 후 다음 loop로 넘어감
            if(S[i] == ' ')
            {
                cout << ' ';
            }
        }
    }
}