#include <iostream>
using namespace std;

static void initRandom( int list[], int n, int max = 100 ) // 랜덤 함수 통해 배열을 0~max-1 값으로 무작위 설정
{
    for(int i = 0; i < n; i++)
        list[i] = rand() % max; // 배열 i번째 인덱스 값을 0~max-1 중 랜덤 값으로 채움
}

static void printArray(int arr[], int n) // 배열 보기 좋게 출력
{
    for( int i = 0; i < n; i++)
        cout << "   " << arr[i];
    
    cout << endl;
}

void insertionSort(int A[], int n)
{
    for(int i = 1; i < n; i++) // 두번째 인덱스부터 n-1번째 인덱스까지
    {
        int key = A[i];
        int j;

        for(j = i-1; j >= 0 && A[j] > key; j--)
            A[j+1] = A[j];
        
        A[j+1] = key;
    }
}

void insertionSortFn(int A[], int n, int(*f)(int, int))
{
    for(int i = 1; i < n; i++)
    {
        int key = A[i];
        int j;

        for(j = i-1; j >= 0 && f(A[j], key) < 0; j--)
            A[j+1] = A[j];
        
        A[j+1] = key;
    }
}

inline int ascend(int x, int y)
{
    return y - x;
}

inline int descend(int x, int y)
{
    return x - y;
}

int main()
{
    int list[16];
    int n = 16;
    initRandom( list, n );

    cout << "Original = ";
    printArray( list, n );

    insertionSortFn( list, n, ascend);
    cout << "Insert-As = ";
    printArray( list, n);

    insertionSortFn( list, n, descend);
    cout << "Insert-De = ";
    printArray( list, n);
}