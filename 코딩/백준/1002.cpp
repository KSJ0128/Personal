#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    cin >> T;

    int test[T], x1, x2, y1, y2, r1, r2, change;
    double d;

    for(int i = 0; i < T; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if(r1 > r2)
        {
            change = r1;
            r1 = r2;
            r2 = change;
        }

        d = sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2));

        if( d == 0) // 같은 위치
        {   
            if( r1 == r2)
                test[i] = -1; // 같은 위치인데 일치하는 경우
            else 
                test[i] = 0; // 같은 위치인데 안 겹치는 경우
        }
        else // 다른 위치
        {
            if(r1 + d == r2 || d == r1 + r2) // 외접하거나 내접하는 경우
                test[i] = 1;

            else if( d > r1 + r2) // 아예 떨어져있는 경우
                test[i] = 0;

            else if( d + r1 < r2 ) // 한 원이 다른 원의 내부에 있는 경우
                test[i] = 0;

            else // 나머지 경우
                test[i] = 2; 
        }
    }    

    for(int i = 0; i < T; i++)
        cout << test[i] << endl;
}