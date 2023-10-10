#include <iostream>
using namespace std;
int main()
{
    int N, K, count, top = 0; // 바퀴의 칸 수, 바퀴 돌리는 횟수, 글자가 바뀐 횟수, 화살표가 가리키는 위치
    char alphabet, wheel[25] = {0}; // 가리키는 글자, 배열
    bool check = true;
    
    cin >> N >> K;

    for(int i = 0; i < K; i++)
    {
        cin >> count >> alphabet;
        top = (top + count) % N; // top 초기화

        if(wheel[top] == 0 || wheel[top] == alphabet)
            wheel[top] = alphabet;
        else
        {
            check = false;
            break;
        }
    }
    
    if(check == false)
        cout << "!";
    else
    {
        for(int i = top, j = 0; j < N; j++)
        {
            if(wheel[i] == 0)
                cout << "?";
            else
                cout << wheel[i];
            
            i = i-1 < 0 ? N-1 : i-1;
        }
    }
}