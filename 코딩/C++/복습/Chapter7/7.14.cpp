#include <iostream>
using namespace std;

void bubbleSort(double num[])
{
    for(int i = 9; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(num[j] > num[j+1])
            {
                double tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    }
}

int main()
{
    double number[10];

    for(int i = 0; i < 10; i++)
    {
        cin >> number[i];
    }

    bubbleSort(number);

    for(int i = 0; i < 10; i++)
    {
        cout << number[i] << " ";
    }
}