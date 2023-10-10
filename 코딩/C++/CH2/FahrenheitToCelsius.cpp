#include <iostream>
using namespace std;

int main()
{
    double celsius, fahrenheit;

    cin >> fahrenheit;
    celsius = (5.0 / 9) * (fahrenheit - 32);
    
    cout << celsius;
}

// 8, 9번째 코드 순서 바뀌면 값이 달라진다. 
// fahrenheit 값이 0으로 인식되어(기본값 = 0) celsius 값이 음수가 된다.