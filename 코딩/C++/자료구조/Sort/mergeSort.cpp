#include <iostream>
using namespace std;
#define MAX_SIZE 1024

static void merge(int A[], int left, int mid, int right) // 2개의 배열 A[left~mid], A[mid+1~right]를 합병
{
    int i, j, k, l; // k는 정렬될 리스트의 인덱스
    static int sorted[MAX_SIZE]; // MAX_SIZE의 배열 선언, 정렬된 배열

    for(i = left, j = mid+1; i <= mid && j <= right; ) // 분할 정렬된 A의 합병
        sorted[k++] = (A[i] <= A[j]) ? A[i++] : A[j++]; // 후위연산자라 A[X] 전달 후 +1 연산

    if(i > mid) // 한쪽에 남은 레코드의 일괄 복사
        for(l = j; l <= right; l++, k++)
            sorted[k] = A[l];
    else // 한쪽에 남은 레코드의 일괄 복사
        for(l = i; l <= mid; l++, k++)
            sorted[k] = A[l];
    
    for(l = left; l <= right; l++)
        A[l] = sorted[l]; // 원래 배열에 정렬된 배열 복사
}

void mergeSort(int A[], int left, int right) // 합병 정렬, int 배열을 오름차순으로 정렬하는 함수
{
    if(left < right)
    {
        int mid = (left + right)/2; // 리스트의 균등 분할
        mergeSort(A, left, mid); // 부분 리스트 정렬
        mergeSort(A, mid + 1, right); // 부분 리스트 정렬
        merge(A, left, mid, right); // 합병
    }
}