#include "10_12.h"
#include <string>
using namespace std;

Stock::Stock(string newSymbol, string newName)
{
    symbol = newSymbol;
    name = newName;
}

const string Stock::getSymbol()
{
    return symbol;
}

const string Stock::getName()
{
    return name;
}

const double Stock::getPreviousClosingPrice()
{
    return previousClosingPrice;
}

const double Stock::getCurrentPrice()
{
    return currentPrice;
}

void Stock::setPreviousClosingPrice(double newPrice)
{
    previousClosingPrice = newPrice;
}

void Stock::setCurrentPrice(double newPrice)
{
    currentPrice = newPrice;
}

const double Stock::getChangePercent()
{
    return currentPrice / previousClosingPrice * 100;
}