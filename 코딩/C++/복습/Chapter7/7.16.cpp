#include <iostream>
using namespace std;

void selectionSort(double num[])
{
    for(int i = 9; i > 0; i--)
    {
        double max = num[i];
        int maxIndex = i;

        for(int j = i-1; j > -1; j--) // int j = i - 1 이 부분이 핵심
        {
            if(num[j] > max)
            {
                max = num[j];
                maxIndex = j;
            }
        }
        double temp = num[i];
        num[i] = max;
        num[maxIndex] = temp;
    }
}

int main()
{
    double num[10];

    for(int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }

    selectionSort(num);

    for(int j = 0; j < 10; j++)
    {
        cout << num[j] <<" ";
    }
}