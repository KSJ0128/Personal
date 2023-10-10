#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
    // 입출력 속도 빠르게 해주는 코드
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    deque<char> deq; // 커서 기준 왼쪽에 있는 문자열
    deque<char> cursor; // 커서 기준 오른쪽에 있는 문자열

    string str; // 편집기에 입력되어 있는 문자열
    cin >> str; // 편집기에 입력되어 있는 문자열 입력

    for(int i = 0; i < str.size(); i++) // 문자열의 길이 만큼 반복
    {
        deq.push_back(str[i]); // 기본 문자열 덱에 세팅
    }

    str = ""; // 문자열 덱에 세팅 후 초기화

    int M; // 입력할 명령어의 개수
    cin >> M; // 명령어 개수 입력
    cin.ignore();

    for(int i = 0; i < M; i++) 
    {
        string cmd; // 명령어
        getline(cin, cmd); // 명령어 입력

        if(cmd[0] == 'L') // L 명령 실행
        {
            if(deq.empty()) // 커서가 문장의 맨 앞인 경우 다음 loop로 넘어감
                continue;
            cursor.push_front(deq.back()); // deq의 back위치 문자를 cursor front에 push
            deq.pop_back(); // 커서 왼쪽에 있는 문자를 커서 오른쪽으로 넘겨주는 과정
        }
        else if(cmd[0] == 'D') // D 명령 실행
        {
            if(cursor.empty()) // 커서가 문장의 맨 뒤인 경우 다음 loop로 넘어감
                continue;
            deq.push_back(cursor.front()); // cursor의 front위치 문자를 deq의 back에 push
            cursor.pop_front(); // 커서 오른쪽에 있는 문자를 커서 왼쪽으로 넘겨주는 과정
        }
        else if(cmd[0] == 'B') // B 명령 실행
        {
            if(deq.empty()) // 커서가 문장의 맨 앞인 경우 다음 loop로 넘어감
                continue;
            deq.pop_back(); // 커서의 왼쪽 문자를 삭제함
        }
        else if(cmd[0] == 'P') // P 명령 실행
        {
            deq.push_back(cmd[2]); // $ 문자를 커서 왼쪽에 push
        }
    }

    while(!cursor.empty()) // 커서 오른쪽에 있는 문자가 사라질 때까지 왼쪽으로 옮겨주는 과정
    {
        deq.push_back(cursor.front());
        cursor.pop_front();
    }

    while(!deq.empty()) // 커서 왼쪽에 있는 문자를 모두 출력하는 과정
    {
        str += deq.front();
        deq.pop_front();
    }

    cout << str;
}