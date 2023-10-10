#include <iostream>
#include <random>
using namespace std;

void printMatrix(int n)
{
// 시드값을 얻기 위한 random_device 생성.
  random_device rd;

  // random_device 를 통해 난수 생성 엔진을 초기화 한다.
  mt19937 gen(rd());

  // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
  uniform_int_distribution<int> dis(0, 1);

  for(int i = 0; i < n; i++) 
  {
    for(int j = 0; j <n; j++)
    {
        cout << dis(gen) << " ";
    }
    cout << endl;
  }
  
  return ;
}

int main()
{
    int num;
    
    cin >> num;

    printMatrix(num);
}