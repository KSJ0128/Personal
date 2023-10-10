#include <iostream>
#include <string>
using namespace std;

int bin2Dec(const string &binaryString) // 2진수 -(정수화)-> 10진수
{
  int value = 0; 

  for (int i = 0; i < binaryString.length(); i++)
  {
    value = value * 2 + binaryString[i] - '0';  
  }

  return value; // 10진수 리턴
}

string dec2Hex(int decimal) // 10진수 -(문자열화)-> 16진수
{
  // Convert decimal to hex
  string hex = "";
    
  while (decimal != 0)
	{
    int hexValue = decimal % 16; // 0 ~ 15
      
    // Convert a decimal value to a hex digit 
    char hexChar = (hexValue <= 9 && hexValue >= 0) ?
      static_cast<char>(hexValue + '0') : // 0 ~ 9 사이일 때  
			static_cast<char>(hexValue - 10 + 'A'); // 10 ~ 15 사이일 때  
      
    hex = hexChar + hex; // 더하는 순서 중요
    decimal = decimal / 16;
  }
    
  return hex;
}

string bin2Hex(const string& binaryString) // 2진수 -> 16진수
{
  int decimal = bin2Dec(binaryString);
  return dec2Hex(decimal);
}

int main()
{
  cout << "Enter a bianry number as a string: ";
  string bianryString;
  cin >> bianryString; // 2진수를 문자열 형태로 입력 받음

  cout << bin2Hex(bianryString) << endl;

  return 0;
}

/*
// 16진수 -> 10진수
int hex2Dec(const string& hex)
{
  int decimalValue = 0;
  for(unsigned i = 0; i < hex.size(); i++)
    decimalValue = decimalValue * 16 + hexCharToDecimal(hex[i]);

  return decimalValue;
}

// 16진수는 문자일 수 있기 때문에 분류하는 과정 필요
int hexCharToDecimal(char ch) 
{
  ch = toupper(ch);
  if(ch >= 'A' && ch <= 'F')
    return 10 + ch - 'A';
  else 
    return ch - '0';
}

int main()
{
  string hex;
  cin >> hex;

  cout << hex2Dec(hex);
}

*/