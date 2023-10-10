#include <iostream>
using namespace std;

bool isConsecutiveFour(const int values[], int size)
{
    bool check = false;

    for(int i = 0; i < size - 4; i++)
    {
        if(values[i] == values[i+1])
        {
            if(values[i+1] == values[i+2])
            {
                if(values[i+2] == values[i+3])
                {
                    check = true;
                    break;
                }
            }
        }
    }

    return check;
}

int main()
{
    int number;
    cin >> number;

    int arr[80];

    for(int i = 0; i < number; i++)
    {
        cin >> arr[i];
    }

    if(isConsecutiveFour(arr, number))
        cout << "The list has consecutive fours";
    else
        cout << "The list has no consecutive fours";
}