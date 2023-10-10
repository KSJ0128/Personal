#include <iostream>
using namespace std;

int main()
{
    double time = (60 * 40 + 35) / 3600.0;
    double kilometer = 24 * 1.6;

    double speed = kilometer / time;

    cout << speed << endl;
}