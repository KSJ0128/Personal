#include <iostream>
using namespace std;

int main()
{
    char C;
    cin >> C;

    if(C >= '0' && C <= '9')
        cout << C - '0' + 48;
    else if(C >= 'A' && C <= 'Z')
        cout << C - 'A' + 65;
    else if(C >= 'a' && C <= 'z') 
        cout << C - 'a' + 97;
}