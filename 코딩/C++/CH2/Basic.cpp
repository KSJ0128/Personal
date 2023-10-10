#include <iostream>
using namespace std;

int main()
{
    int i = 1, j = 2, k = 3; // = int i(1), j(2), k(3);  // int i, j, k = 1; (X)

    i = j = k = 1;

    // cout << i = 1; 
    // = i = 1;
    // cout<< i;

    const double PI = 3.14159; // 상수 선언, 대문자로 선언, 변경 불가능

    /* 
    정수: long > int > short, unsigned > signed
    실수: long double > double > float

    변수, 데이터 유형의 크기: sizeof 함수  // sizeof(int), sizeof(i) 등 

    리터럴: 직접 사용되는 상수 // 8진수 리터럴: 0... , 16진수 리터럴: 0X...

    지수 연산 함수: pow(a, b) // a의 b제곱, pow 함수는 cmath 라이브러리에 저장되어있음
    ** 1.23e+2 = 123, 123e-2 = 1.23s

    전위 연산자: 연산자 먼저 적용 후 수식 연산, 후위 연산자: 수식 연산 후 연산자 적용

    static_cast<type>(value) == type i = (type)value  // value를 type으로 형 변환 
    */
}