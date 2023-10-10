#ifndef STOCK_H
#define STOCK_H
#include <string>
using namespace std;

class Stock
{
    public:
    Stock(string, string);
    const string getSymbol();
    const string getName();
    const double getPreviousClosingPrice();
    const double getCurrentPrice();
    void setPreviousClosingPrice(double);
    void setCurrentPrice(double);
    const double getChangePercent();

    private:
    string symbol;
    string name;
    double previousClosingPrice;
    double currentPrice;
};

#endif