#include <iostream>
using namespace std;

// swap, selectionSort 함수가 메인!
// static으로 선언한 이유: 함수를 파일 내에서만 사용하므로 캡슐화!

void swap( int& x, int& y ) // 두 값 교환, 포인터로 받아서 실제 값 변화해줌!
{
    int t = x;
    x = y;
    y = t;
}

void selectionSort( int A[], int n) // 배열을 오름차순으로 선택 정렬
{
    for(int i = 0; i < n-1; i++) // n-1회(= 요소의 개수 -1) 반복
    {
        int least = i; // 배열의 앞쪽부터 정렬하기 위함
        
        for(int j = i+1; j < n; j++) // least번째 인덱스 이후 인덱스 값 중 최솟값 존재하는지 체크
        {    
            if(A[j] < A[least]) // least번째 인덱스 값보다 작은 값 있다면 교환
                least = j;
        }

        swap(A[i], A[least]);
    }
}

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

int main() // 정렬할 배열을 입력 받고 선택 정렬 통해 출력하는 형태로 사용!
{
    int list[16];
    int n = 16;

    initRandom( list, n);
    cout << "Original = "; 
    printArray( list, n);
    selectionSort( list, n );
    cout << "Selection = "; 
    printArray( list, n);
}