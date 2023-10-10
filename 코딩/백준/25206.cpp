#include <iostream>
#include <string>
using namespace std;

int main()
{
    string subject, grade;
    double credit, scoreMean = 0.0, creditSum = 0.0;

    for(int i = 0; i < 20; i++)
    {
        cin >> subject >> credit >> grade;

        if(grade == "A+")
            scoreMean += credit * 4.5;
        else if(grade == "A0")
            scoreMean += credit * 4.0;
        else if(grade == "B+")
            scoreMean += credit * 3.5;
        else if(grade == "B0")
            scoreMean += credit * 3.0;
        else if(grade == "C+")
            scoreMean += credit * 2.5;
        else if(grade == "C0")
            scoreMean += credit * 2.0;
        else if(grade == "D+")
            scoreMean += credit * 1.5;
        else if(grade == "D0")
            scoreMean += credit * 1.0;
        else if(grade == "F")
            scoreMean += credit * 0.0;
        else if(grade == "P")
            continue;
        creditSum += credit;
    }
    cout.precision(7);
    cout << scoreMean / creditSum;
}