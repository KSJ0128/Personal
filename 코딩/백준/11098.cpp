#include <iostream>
using namespace std;
int main()
{
    int n, p, C1, C2;
    string name1, name2, name[100];

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> p; // 테스트 케이스 개수 만큼 선수의 수 입력 받음

        for(int j = 0; j < p; j++)
        {
           cin >> C1 >> name1;
           
           if(C1 > C2)
           {
               name2 = name1;
               C2 = C1;
           }
        }
        name[i] = name2; // 각 케이스별 최고가 선수 저장
        C2 = 0; // C2 값 초기화 하지않으면 이전 케이스 최고값보다 현재 케이스 최고값이 적은 경우 갱신 안됨.
    }

    for(int i = 0; i < n; i++)
    {
        cout << name[i] << endl;
    }
}