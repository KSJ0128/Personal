#include <iostream>
using namespace std;

// 10진수 -> 16진수
// 우선 문자 하나씩 문자열에 삽입 -> 순서가 거꾸로라 reverse 함수 통해 뒤집기

void reverse(char hexString[])
{
    char tmp;
    int len = strlen(hexString);

    for(int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        tmp = hexString[i];
        hexString[i] = hexString[j];
        hexString[j] = tmp;
    }
}

void dec2Hex(int value, char hexString[])
{
    int i = 0;
    while(value != 0)
    {
        int remain = value % 16;

        char hexChar = (remain <= 9 && remain >= 0) ?
            static_cast<char>(remain + '0') : // 0 ~ 9 사이일 때  
			static_cast<char>(remain - 10 + 'A'); // 10 ~ 15 사이일 때  

        hexString[i++] = hexChar;
        value = value / 16;
    }   
    reverse(hexString);
}

int main()
{
    int dec;
    cin >> dec;

    char hex[100] = "";

    dec2Hex(dec, hex);

    cout << hex;
}