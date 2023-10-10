#include <iostream>
using namespace std;

void swapCase(const char s1[], char s2[])
{
    for(int i = 0; i < strlen(s1); i++)
    {
        if(s1[i] >= 97 && s1[i] <= 122)
            s2[i] = s1[i] - 32;

        else if(s1[i] >= 65 && s1[i] <= 90)
            s2[i] = s1[i] + 32;

        else
            s2[i] = s1[i];
    }

    cout << s2;
}

int main()
{
    char s1[100], s2[100];
    cin.getline(s1, 100, '\n');

    swapCase(s1, s2);
}