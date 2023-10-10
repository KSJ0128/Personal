#include <iostream>
using namespace std;
int main()
{
    bool submit[30] = {false};
    int num;

    for(int i = 0; i < 28; i++)
    {
        cin >> num;
        submit[num-1] = true;
    }

    for(int i = 0; i < 30; i++)
    {
        if(submit[i] == false)
            cout << i+1 << endl;
    }
}