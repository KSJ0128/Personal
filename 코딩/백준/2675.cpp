#include <iostream>
#include <string>
using namespace std;
int main()
{
   int T; cin >> T;

   for(int i = 0; i < T; i++)
   {
       int R; cin >> R;
       string s; cin >> s;
       
       string S = "";

       for(int j = 0; j < s.length(); j++)
       {
           for(int k = 0; k < R; k++)
                S += s.at(j);
       }
       cout << S << endl;
    }
}