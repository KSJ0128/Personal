#include <iostream>
#include <algorithm>
using namespace std;

int uniqueNum(int* list, int size)
{
    int num = 0, index = 0;

    for(int i = 0; i < size; i++)
    {
        cin >> num;

        int* p = find(list, list+size, num);

        if(p == list + size)
            list[index++] = num;
        else
            continue;

    }
    return index;
}

int main()
{
    int size;
    cin >> size;

    int* list = new int [size];
    
    int realSize = uniqueNum(list, size);

    for(int i = 0; i < realSize; i++)
    {
        cout << list[i] << " ";
    }

}