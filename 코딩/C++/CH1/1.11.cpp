#include <iostream>
using namespace std;

int main()
{
    int time = 60 * 60 * 24 * 365;
    int population = 312032486;

    double birth = time / 7.0;
    double death = time / 13.0;
    double immigrant = time / 45.0;

    cout<< population + birth * 1 - death * 1 - immigrant * 1 << endl
    << population + birth * 2 - death * 2 - immigrant * 2 << endl
    << population + birth * 3 - death * 3 - immigrant * 3 << endl
    << population + birth * 4 - death * 4 - immigrant * 4 << endl
    << population + birth * 5 - death * 5 - immigrant * 5 <<endl;
}