#include <iostream>
#include <string>
#include <stack>
using namespace std;

// LIFO의 특성을 가진 stack을 활용한다. 공백을 기준으로 문자를 stack에 push, pop해 단어를 뒤집어준다.
int main()
{   
    // 실행 속도 높여주는 코드
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> s; // 단어의 알파벳 하나씩 저장하기 위한 stack
    string str; // 입력 받을 문장
    int T; // 테스트 케이스의 개수
    cin >> T; // 테스트 케이스 개수 입력
    cin.ignore(); // cin과 getline 같이 사용할 때 입력 버퍼에 \n이 전달되어 입력 버퍼 초기화해줌

    for(int i = 0; i < T; i++)
    {
        getline(cin, str); // 문장 공백 포함해서 입력
        string reverse = ""; // 단어 뒤집힌 문장 저장하기 위한 변수

        for(int j = 0; j < str.size(); j++) // 입력 받은 문장의 길이 만큼 반복
        {
            if(str[j] != ' ') // str의 j번째 인덱스가 공백이 아닐 경우
            {
                s.push(str[j]); // 스택에 문자 push

                if(j == str.size() - 1) // 마지막 인덱스인 경우 stack의 모든 문자를 pop해 reverse에 덧붙인다.
                {
                    while(!s.empty())
                    {
                        reverse += s.top();
                        s.pop();
                    }
                }
            } 
            else// 공백 입력된 경우
            {
                while(!s.empty()) // 스택에 저장되어 있던 모든 문자를 pop해 reverse에 덧붙인다.
                {
                    reverse += s.top();
                    s.pop();
                }
                reverse += ' ';
            }
        }
        cout << reverse << endl; // reverse 출력
    }
}