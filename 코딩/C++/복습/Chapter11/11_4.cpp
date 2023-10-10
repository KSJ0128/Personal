#include <iostream>
using namespace std;

int average(const int* array, int size)
{
    int avg = 0;

    for(int i = 0; i < size; i++)
    {
        avg += array[i];
    }

    avg /= size;

    return avg;
}

double average(const double* array, int size)
{
    double avg = 0;

    for(int i = 0; i < size; i++)
    {
        avg += array[i];
    }

    avg /= size;

    return avg;
}

int main()
{
    double list[10];
    for(int i = 0; i < 10; i++)
    {
        cin >> list[i];
    }

    cout << average(list, 10);
}