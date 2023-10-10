#include <iostream>
using namespace std;

// check, sum을 0으로 초기화 시키면 성공함. 초기화 중요.

int main()
{
    int M, N, sum, check, min;
    check=0; sum=0;

    cin >> M >> N;

    for(int i = M; i <= N; i++) // M이상 N이하인 자연수
    {
        for(int j = 2; j < i; j++) // 2~i보다 작은 자연수로 나눠보기
        {
            if(i % j == 0) // i가 소수가 아닐 때
            {
               check = 1; // check를 1로 변경 후 반복문 탈출( 다음 수로 점프 )
               break;
            }
        }

        if( check == 0 && i != 1) // 소수일 때
        {
            if(sum == 0) // 첫 소수 일 때 최솟값 초기화
                min = i;

            sum += i; // sum 초기화
        }
        check = 0; // 약수 유무 초기화
    }

    if( sum == 0 )
        cout << -1;
    else
        cout << sum << endl << min;
}