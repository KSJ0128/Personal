#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    int* p = &i;

    cout << p << endl; // 0x16f5833cc
    cout << *p << endl; // 10
    (*p)++;
    cout << p << endl; // 0x16f5833cc
    cout << *p << endl; // 11
    *p++;
    cout << p << endl; // 0x16eedf3d0
    cout << *p << endl; // 11
    *(p++);
    cout << p << endl; // 0x16f5833cc
    cout << *p << endl; // 11
}