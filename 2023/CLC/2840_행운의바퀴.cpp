#include <iostream>
#include <list>
using namespace std;
int main()
{
    int N, K, count, top = 0; // 바퀴 칸 수, 바퀴 돌리는 횟수, 글자 바뀌는 횟수
    char alphabet; // 가리키는 글자
    bool check = true, overlap[26] = {false}; // 알파벳 26개이므로 overlap 크기도 26으로 할당 !
    list<char> wheel(25);
    list<char>:: iterator iter; // iter: 리스트 위치 가리킴

    cin >> N >> K;

    for(int i = 0; i < K; i++)
    {
        cin >> count >> alphabet;
        top = (top + count) % N; // top 초기화

        int j = 0;
        iter = wheel.begin();

        while(j < top) // iter 초기화
        {
            j++; iter++; 
        }

        if(*iter == 0) // 룰렛 위치에 입력된 알파벳이 없는 경우
        {
            if(overlap[alphabet - 'A'] == true) // 입력할 알파벳이 이미 룰렛에 입력된 경우
                check = false;
            else // 입력할 알파벳이 룰렛에 없는 경우
            {
                overlap[alphabet - 'A'] = true;
                *iter = alphabet;
            }
        }
        else if (*iter == alphabet) // 룰렛 위치에 같은 알파벳이 입력되어 있을 때
        {
            continue;
        }
        else // 룰렛 위치에 다른 알파벳이 입력되어 있을 때
            check = false;
    }

    if(check == false) // 잘못된 바퀴인 경우
        cout << "!";
    else 
    {
        for(int i = 0, j = top; i < N; i++) // 바퀴 개수 만큼 반복, 룰렛 화살표가 마지막으로 가리킨 알파벳부터 시작
        {
            if(*iter == 0) // 룰렛 비어있을 때
                cout << "?";
            else // 룰렛 차 있을 때
                cout << *iter;

            if(j == 0) // j와 iter를 감소시키기 때문에 0 이하로 가면 N-1로 리셋
            {
                while(j != N-1)
                {
                    iter++;
                    j++;
                }
            }
            else // 매 반복마다 j와 iter 감소
            {
                iter--;
                j--;
            }
        }
    }
}