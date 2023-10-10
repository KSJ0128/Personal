#include <iostream>
using namespace std;

long long mult(long long A, long long B, long long C)
{
    if(B == 1)
        return A % C;
    /*
    기본
    return (A * mult(A, B-1, C)) % C;
    */
    else
    {
        long long result = mult(A, B/2, C); // 메모리 줄이기 위해 연산 2분의 1
        result = (result * result) % C;

        if(B % 2 == 0) // B가 짝수일 때
            return result;
        else // B가 홀수일 때
            return (result * A) % C;
    }

}

int main()
{
    long long A, B, C; // A: 곱하는 수, B: 곱할 횟수, C: 모듈러
    cin >> A >> B >> C;

    cout << mult(A, B, C);
}