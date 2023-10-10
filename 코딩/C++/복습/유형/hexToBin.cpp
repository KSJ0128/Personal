#include <iostream>
#include <string>
using namespace std;

// 16진수 -> 2진수

int hexChartoDec(char c)
{
    c = toupper(c);

    if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return c - '0';
}

int hexToDec(const string& hex) // 16진수 -(정수화)-> 10진수
{
    int result = 0;

    for(int i = 0; i < hex.size(); i++)
        result = result * 16 + hexChartoDec(hex[i]);

    return result;
}

string decToBin(int dec) // 10진수 -> 2진수 // 여기가 문제
{
    string bin = "";

    while(dec != 0)
    {
        int binValue = dec % 2;
        
        char binChar = static_cast<char>(binValue + '0');

        bin = binChar + bin;
        dec = dec / 2;
    }

    return bin;
}

string hexToBin(const string& hex) // 16진수 -> 2진수
{
    int decimal = hexToDec(hex);

    return decToBin(decimal);
}

int main()
{
    string hexString;
    cin >> hexString;

    cout << hexToBin(hexString);

    return 0;
}