#include <iostream>
#include <string>
using namespace std;

void reverse(int number)
{
    string str = "";

    while(number != 0)
    {
        str += to_string(number % 10); // 숫자 -> 문자열
        number = number / 10;
    }

    cout << str;
}

/* 
string으로 변환하지 않고, 맨 뒤 숫자만 떼서 한 글자씩 출력

void reverse(int number) 
{
  while (number != 0) 
  {
    int remainder = number % 10;
    cout << remainder;
    number = number / 10;
  }
}
*/

int main()
{
    int num;

    cin >> num;

    reverse(num);
}