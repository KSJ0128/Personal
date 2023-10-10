#include <iostream>
using namespace std;

int main()
{
    int time, minute, second;
    cin >> time;

    minute = time / 60;
    second = time  % 60;

    cout<< minute << "분" << second << "초" << endl;

    return 0;
}