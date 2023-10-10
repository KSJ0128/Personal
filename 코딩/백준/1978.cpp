#include <iostream>
using namespace std;

int main()
{
    int N, number, check;
    int count = 0;

    cin >> N;

    for(int i = 0; i < N; i++) 
    {

        cin >> number;

        for(int j = 2; j < number; j++) // 2~i보다 작은 자연수로 나눠보기
        {
            if(number % j == 0) // i가 소수가 아닐 때
            {
               check = 1; // check를 1로 변경 후 반복문 탈출( 다음 수로 점프 )
               break;
            }
        }

        if( check == 0 && number != 1) // 소수일 때
        {
            count += 1;
        }
        check = 0; // 약수 유무 초기화
    }

    cout << count;
}