#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include "OptionPricing.h"
#include "MonteCarloSimulation.h"

class Portfolio
{
public:
    Portfolio(double S0, double sigma, double r, double d, double T, double K1, double K2, double K3, double K4);
    double pricePortfolio(double barrierLevel);

private:
    double S0, sigma, r, d, T, K1, K2, K3, K4;
};

#endif // PORTFOLIO_H
