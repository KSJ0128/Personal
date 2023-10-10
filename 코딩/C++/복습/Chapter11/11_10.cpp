#include <iostream>
#include <string>
using namespace std;

int* count(const string& s)
{
    int* num = new int[26]();

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'A' || s[i] == 'a')
            num[0]++;
        else if(s[i] == 'B' || s[i] == 'b')
            num[1]++;
        else if(s[i] == 'C' || s[i] == 'c')
            num[2]++;
        else if(s[i] == 'D' || s[i] == 'd')
            num[3]++;
        else if(s[i] == 'E' || s[i] == 'e')
            num[4]++;
        else if(s[i] == 'F' || s[i] == 'f')
            num[5]++;
        else if(s[i] == 'G' || s[i] == 'g')
            num[6]++;
        else if(s[i] == 'H' || s[i] == 'h')
            num[7]++;
        else if(s[i] == 'I' || s[i] == 'i')
            num[8]++;
        else if(s[i] == 'J' || s[i] == 'j')
            num[9]++;
        else if(s[i] == 'K' || s[i] == 'k')
            num[10]++;
        else if(s[i] == 'L' || s[i] == 'l')
            num[11]++;
        else if(s[i] == 'M' || s[i] == 'm')
            num[12]++;
        else if(s[i] == 'N' || s[i] == 'n')
            num[13]++;
        else if(s[i] == 'O' || s[i] == 'o')
            num[14]++;
        else if(s[i] == 'P' || s[i] == 'p')
            num[15]++;
        else if(s[i] == 'Q' || s[i] == 'q')
            num[16]++;
        else if(s[i] == 'R' || s[i] == 'r')
            num[17]++;
        else if(s[i] == 'S' || s[i] == 's')
            num[18]++;
        else if(s[i] == 'T' || s[i] == 't')
            num[19]++;
        else if(s[i] == 'U' || s[i] == 'u')
            num[20]++;
        else if(s[i] == 'V' || s[i] == 'v')
            num[21]++;
        else if(s[i] == 'W' || s[i] == 'w')
            num[22]++;
        else if(s[i] == 'X' || s[i] == 'x')
            num[23]++;
        else if(s[i] == 'Y' || s[i] == 'y')
            num[24]++;
        else if(s[i] == 'Z' || s[i] == 'z')
            num[25]++;
        else
            continue;
    }

    return num;
}

int main()
{
    string str;
    cin >> str;

    int* p = count(str);

    for(int i = 0; i < 26; i++)
        cout << p[i] << endl;
}