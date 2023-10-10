#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int s = a;
    a = b;
    b = s;
}

void selectionSort(int list[], int N) // 배열을 매개변수로 사용시 주소로 전달
{
    for(int i = 0; i < N-1; i++)
    {
        int least = i;

        for(int j = i+1; j < N; j++)
        {
            if(list[j] < list[least])
                least = j;
        }
        swap(list[i], list[least]);
    }

}

int main()
{
    int N;
    cin >> N;

    int number[N]; // 0으로 초기화하면 안됨
    
    for(int i = 0; i < N; i++)
        cin >> number[i];

    selectionSort(number, N); // number[] 말고 number로 전달해야됨
    
    for(int i = 0; i < N; i++)
        cout << number[i] << endl;
}