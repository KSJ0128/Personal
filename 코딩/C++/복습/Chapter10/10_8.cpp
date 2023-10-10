#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// 11.56
// : 2, 1 0, 6 4
void computeChange(const string str, int& dollar, int& cent)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str.at(i) == '.')
        {
            dollar = stoi(str.substr(0, i));
            cent = stoi(str.substr(i+1));
            
            break;
        }
    }
}

int main()
{
    int dollar = 0, cent = 0, quarter = 0, dime = 0, nickel = 0, penny = 0;
    string str("");
    cout << "금액: ";
    cin >> str;

    computeChange(str, dollar, cent);

    quarter = cent / 25;
    dime = cent % 25 / 10;
    nickel = cent % 25 % 10 / 5;
    penny = cent % 25 % 10 % 5;

    printf("Dollar: %d \nQuarter: %d\nDime: %d\nNickel: %d\nPenny: %d\n", dollar, quarter, dime, nickel, penny);
}