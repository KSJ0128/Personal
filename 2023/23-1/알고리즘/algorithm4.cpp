#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const int SIZE = 97;

void arrayCopy(string birth[], string copy[])
{
    for(int i = 0; i < SIZE; i++)
    {
        copy[i] = birth[i];
    }
}

int partition(string arr[], int low, int high)
{
    string pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(i <= j)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i <= j)
            swap(arr[i++], arr[j--]);
    }
    swap(arr[low], arr[j]);

    return j;
}

void basicQuickSort(string arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        basicQuickSort(arr, low, pivot-1);
        basicQuickSort(arr, pivot+1, high);
    }
}

int getMedian(string arr[], int low, int high)
{
    sort(arr, arr + high + 1);
    return (low + high) / 2;
}

int choosePivot(string arr[], int low, int high)
{
    if(high - low <= 5)
        return getMedian(arr, low, high);
    else
    {
        int current = low;
        for (int i = low; i <= high; i += 5) 
        { 
            // 데이터 셋을 크기가 5 인 그룹으로 쪼개서 각 그룹의 중간값을 찾는다.
            int med = getMedian(arr, i, min(i + 4, high));

            // 각 그룹의 중간값을 맨 앞으로 가져온다.
            swap(arr[current], arr[med]);
            current++;
        }
        return choosePivot(arr, low, current);
    }
}

void medianOfMedians(string arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = choosePivot(arr, low, high);
        medianOfMedians(arr, low, pivot-1);
        medianOfMedians(arr, pivot+1, high);
    }
}

void tupleSort(string birth[], string copy[])
{
    for(int i = 0; i < SIZE; i++)
    {
        copy[i] = birth[i].substr(3) + '.' + birth[i].substr(0,2); // dd.mm
    }
    
    basicQuickSort(copy, 0, SIZE);
    
    for(int i = 0; i < SIZE; i++)
    {
        copy[i] = copy[i].substr(3) + '.' + copy[i].substr(0,2); // dd.mm
    }
}

int main()
{
    int count = 0;
    string birth[SIZE];
    string copy[SIZE];
    ifstream fs;
    fs.open("birthday3.txt");

    while(!fs.eof()) // birthday 데이터 셋 불러오기
    {
        fs >> birth[count++];
    }
    fs.close();

    tupleSort(birth, copy);
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << copy[i] << endl;
    }
}