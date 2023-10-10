#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

int selectionSort(int sort[])
{
    for(int i = 0; i < 9; i++)
    {
        int least = i;

        for(int j = i+1; j < 10; j++)
        {
            if(sort[least] > sort[j])
                least = j;
        }
        swap(sort[i], sort[least]);
    }
    return sort[7];
}

int main()
{
    int T, sort[10];
    cin >> T;

    int three[T];

    for(int i = 0; i<T; i++)
    {
        for(int j = 0; j < 10; j++)    
            cin >> sort[j];
        three[i] = selectionSort(sort);
    }

    for(int k = 0 ; k < T; k++)
        cout << three[k] << endl;
}