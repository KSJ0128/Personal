#include <iostream>
using namespace std;

int main()
{
    int amount;
    cin >> amount;

    // 11dollar 56cent
    // 11dollar
    int numberOfDollors = amount / 100;  
    amount %= 100;

    // 56cent
    int numberOfQuarters = amount / 25;   // 25cent
    amount %= 25;

    int numberOfDimes = amount / 10;   // 10cent
    amount %= 10;

    int numberOfNickels = amount / 5;   // 5cent
    amount %= 5;

    int numberOfPennies = amount;   // 1cent

    cout<< amount << endl << numberOfDollors << endl << numberOfQuarters << endl
    << numberOfDimes << endl << numberOfNickels << endl << numberOfPennies;
}