#include <iostream>
#include "Portfolio.h"

int main()
{
    double S0 = 115;
    double sigma = 0.25;
    double r = 0.05;
    double d = 0.0;
    double T = 5.0 / 12.0;
    double K1 = 100;
    double K2 = 110;
    double K3 = 120;
    double K4 = 130;

    Portfolio portfolio(S0, sigma, r, d, T, K1, K2, K3, K4);
    double barrierLevel = S0 * 0.8;

    double price = portfolio.pricePortfolio(barrierLevel);
    std::cout << "Portfolio price: " << price << std::endl;

    return 0;
}
