#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int list[] = {3,4,2,5,6,1};
    cout << *min_element(list,list+2) << endl << *max_element(list,list+2) << endl <<
        *find(list,list+6,2) << endl << find(list, list+6, 20) << endl;
    sort(list,list+6);
    cout << list[5];
}