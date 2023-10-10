#include <iostream>
using namespace std;
int main() // 미완성
{
    int n, d, m, y;
    int mind, minm, miny, maxd, maxm, maxy = 0;
    string name;
    string minname, maxname = "";

    cin >> n;
    
    for(int i = 0; i < n; i++) // 입력 받은 학생 수만큼 학생 데이터 입력 받기
    {
        cin >> name >> d >> m >> y;

        if((miny == 0) && (maxy == 0)) // 첫 입력일때 초기화
        {
            miny = y;
            minm = m;
            mind = d;
            minname = name;

            maxy = y;
            maxm = m;
            maxd = d; 
            maxname = name;
        }
        else if(miny <= y) // 첫 입력 아니고 가장 나이 적은 사람 초기화
        {
            if(miny == y)
            {
                if(minm <= m)
                {
                    if(minm == m)
                    {
                        if(mind < d)
                        {
                            miny = y;
                            minm = m;
                            mind = d;
                            minname = name;
                        }
                    }
                    else
                    {
                        miny = y;
                        minm = m;
                        mind = d;
                        minname = name;
                    }
                }
            }
            else
            {
                miny = y;
                minm = m;
                mind = d;
                minname = name;
            }
        }
        else if(maxy >= y) // 첫 입력 아니고 가장 나이 많은 사람 초기화
        {
            if(maxy == y)
            {
                if(maxm >= m)
                {
                    if(maxm == m)
                    {
                        if(maxd > d)
                        {
                            maxy = y;
                            maxm = m;
                            maxd = d;
                            maxname = name;
                        }
                    }
                    else 
                    {        
                        maxy = y;
                        maxm = m;
                        maxd = d;
                        maxname = name;
                    }
                }
            }
            else 
            {
                maxy = y;
                maxm = m;
                maxd = d;
                maxname = name;
            }
        }
    }
    cout << minname << endl << maxname;
}