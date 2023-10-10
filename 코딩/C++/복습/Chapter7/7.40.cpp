#include <iostream>
using namespace std;

void reverse(char hexString[])
{
    int len = strlen(hexString);

    for(int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        int tmp = hexString[i];
        hexString[i] = hexString[j];
        hexString[j] = tmp;
    }
}

void dec2Hex(int decimal, char hexString[])
{
    int i = 0;

    while(decimal != 0)
    {
        int remainder = decimal % 16;

        char hexChar = remainder >= 10 ? 
            static_cast<char>(remainder + 55):
            static_cast<char>(remainder + 48);

        hexString[i++] = hexChar;
        decimal = decimal / 16;
    }

    reverse(hexString);
}

int bin2Dec(const char binaryString[])
{
    int decimal = 0;

    for(int i = 0; i < strlen(binaryString); i++)
    {
        decimal = decimal * 2 + binaryString[i] - '0'; 
        // binaryString[i] = '1'인 경우 '1' - '0'는 아스키코드 상 1 차이나므로 1로 처리
    }

    return decimal;
}

// 2진수 -> 16진수
void bin2Hex(const char binaryString[], char hexString[])
{
    int decimal = bin2Dec(binaryString);
    dec2Hex(decimal, hexString);
    
    cout << hexString;
}

int main()
{
    char bin[100], hex[100] = "";
    cin >> bin;

    bin2Hex(bin, hex);
}