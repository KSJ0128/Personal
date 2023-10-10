#include <iostream>
// "iostream" 이라는 라이브러리(=헤더 파일) 포함.
// iostream은 화면 입출력을 담당.
// 전처리기 지시자는( # 뒤에 오는 것 ) C++ 문장이 아니므로 ; 붙이면 안됨.
// < 와 > 사이에 공백 포함하지 않기.c

using namespace std;
// 표준 네임 스페이스를 사용한다는 뜻.
// 이를 통해 iostream 라이브러리에서 cout, endl 등의 이름을 찾음.

int main() 
// C++은 하나의 main 함수가 필요.
// Main이 아니고 main
{
    cout << "hello world" << endl;
    // cout: 콘솔 출력, endl: 마지막 줄(줄바꿈) 의미, 출력할 내용 밀어내 즉시 화면에 표시.
    // << 는 콘솔로 출력할 내용
    // 모든 문장의 끝엔 ; .

    return 0;
    //프로그램의 종료.
    // 예약어(키워드): using, namespace, int, return
}