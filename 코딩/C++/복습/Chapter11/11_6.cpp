#include <iostream>
#include <string>
using namespace std;

void printArray(const int* counts, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << counts[i] << " ";
    }
}

void count(const string& s, int counts[], int size)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '0')
            counts[0]++;
        else if(s[i] == '1')
            counts[1]++;
        else if(s[i] == '2')
            counts[2]++;
        else if(s[i] == '3')
            counts[3]++;
        else if(s[i] == '4')
            counts[4]++;
        else if(s[i] == '5')
            counts[5]++;
        else if(s[i] == '6')
            counts[6]++;
        else if(s[i] == '7')
            counts[7]++;
        else if(s[i] == '8')
            counts[8]++;
        else if(s[i] == '9')
            counts[9]++;
        else
            continue;
    }

    printArray(counts, 10);
}

int main()
{
    string str = "SSN is 343 32 4545 and ID is 434 34 4323";
    int counts[10] = {0,};

    count(str, counts, 10);
}