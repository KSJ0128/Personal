#include <iostream>
#include <string>
#include "10_12.h"
#include "10_12.cpp"
using namespace std;

int main()
{
    Stock stock("MSFT", "Microsoft Corporation");
    stock.setPreviousClosingPrice(27.5);
    stock.setCurrentPrice(27.6);

    cout << stock.getChangePercent();
}