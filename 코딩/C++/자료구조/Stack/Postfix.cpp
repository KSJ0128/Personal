#include <iostream>
#include "Postfix.h"
using namespace std;

int main()
{
    Postfix post1;
    string s;
    
    cout << "계산 식을 입력해주세요: ";
    cin >> s;

    cout << post1.allCalculate(s);
}