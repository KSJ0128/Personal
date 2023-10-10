#include <iostream>
#include <string>
using namespace std;
int main()
{
    string A, B; cin >> A >> B;
    string a, b = ""; 
    
    for(int i = 2; i >= 0; i--)
    {
        a += A.at(i);
        b += B.at(i);
    }

    if(a > b)
        cout << a;
    else 
        cout << b;

}