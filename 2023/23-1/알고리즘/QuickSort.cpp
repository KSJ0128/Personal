#include <iostream>
using namespace std;
const int SIZE = 100;

void putArray(double* birth) // Put them into your unsorted array using set.
{
    for(int i = 0; i < 100; i++)
        cin >> birth[i];
}

int main()
{
    double birth[SIZE];
    putArray(birth);


}