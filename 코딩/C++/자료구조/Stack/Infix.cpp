#include <iostream>
#include "Infix.h"
using namespace std;

int main()
{
    Infix if1;
    string s;

    cin >> s;

    if1.allCalculate(s);
}

// 계산 순서: () -> *, / -> +, -