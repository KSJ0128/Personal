#include <iostream>
using namespace std;

bool strictlyEqual(const int list1[], const int list2[], int size)
{
    bool equal = true;

    for(int i = 0; i < size; i++)
    {
        if(list1[i] == list2[i] && list1[i]== -1)
            break;

        if(list1[i] != list2[i] || list1[i] == -1 || list2[i] == -1)
        {
            equal = false;
            break;
        }
    }

    return equal;
}

int main()
{
    int list1[20], list2[20];

    for(int i = 0; i < 20; i++)
    {
        cin >> list1[i];
        if(list1[i] < 0)
            break;
    }

    for(int j = 0; j < 20; j++)
    {
        cin >> list2[j];
        if(list2[j] < 0)
            break;
    }

    if(strictlyEqual(list1, list2, 20))
        cout << "Two lists are strictly identical!";
    else
        cout << "Two lists are not strictly identical!";
}