#include <iostream>
#include <stack>
using namespace std;


/*
틀린 이유
1. check 변수 초기화
2. stack 초기화
*/
int main()
{
    stack<char> b; // 입력 받은 괄호를 한 개씩 저장할 스택
    int T; // 테스트 데이터의 개수
    cin >> T; // 테스트 데이터 입력

    for(int i = 0; i < T; i++)
    {
        bool check = true; // 올바른 괄호 문자열인지 체크하기 위한 bool 변수
        string str; // 괄호 문자열
        cin >> str; // 괄호 문자열 입력

        for(int j = 0; j < str.size(); j++) // 입력 받은 괄호 문자열의 길이 만큼 반복
        {
            if(str[j] == '(') // 괄호 문자열의 j번째 괄호가 (인 경우
                b.push('('); // 스택에 (를 push
            else // 괄호 문자열의 j번째 괄호가 )인 경우
            {
                // 스택이 비어있지 않고, 스택의 top이 (면 pop 실행 == pop 가능한 케이스
                if(!b.empty() && b.top() == '(') // 스택이 비어있는 경우 메모리 에러, 스택의 top이 )인 경우 올바른 문자열이 아님.
                    b.pop();
                else // pop 불가한 케이스
                {
                    check = false; // bool 변수를 false로 초기화.
                    break; // 반복문 탈출. 해당 테스트 데이터가 올바른 문자열이 아님을 알았기 때문에
                }
            }
        }

        if(!b.empty()) // 스택이 비어있지 않은 경우 올바른 문자열이 아님. 괄호의 짝이 맞지 않는 경우이므로.
            check = false;

        if(check == true) // 변수 check가 true인 경우 올바른 문자열.
            cout << "YES" << endl;
        else              // 변수 check가 false인 경우 잘못된 문자열.
            cout << "NO" << endl;

        // stack 초기화, 다음 테스트 데이터가 올바른 문자열인지 체크하기 위해
        while(!b.empty())
            b.pop();
    }
}