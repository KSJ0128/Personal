#include <iostream>
using namespace std;

void merge(const int list1[], int size1, const int list2[], int size2, int list3[])
{
    int size = size1 + size2;

    // 리스트 병합
    for(int i = 0; i < size1; i++)
    {
        list3[i] = list1[i];
        list3[size1+i] = list2[i];
    }    

    int minIndex, tmp;

    // 리스트 정렬
    for(int i = 0; i < size-1; i++)
    {       
        minIndex = i;

        for(int j = i+1; j < size; j++)
        {
            if(list3[minIndex] > list3[j])
                minIndex = j;
        }
        tmp = list3[i];
        list3[i] = list3[minIndex];
        list3[minIndex] = tmp;
    }
}

int main()
{
    int list1[80], list2[80], list3[160], cnt1, cnt2;

    // 리스트1 입력
    cin >> cnt1;

    for(int i = 0; i < cnt1; i++)
    {
        cin >> list1[i];
    }

    // 리스트2 입력
    cin >> cnt2;

    for(int i = 0; i < cnt2; i++)
    {
        cin >> list2[i];
    }

    merge(list1,cnt1,list2,cnt2,list3);

    for(int i = 0; i < cnt1+cnt2; i++)
    {
        cout << list3[i] << " ";
    }
}