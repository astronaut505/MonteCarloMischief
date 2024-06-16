#ifndef PORTFOLIO_PRICING_H
#define PORTFOLIO_PRICING_H

class Portfolio
{
public:
    Portfolio(double S0, double sigma, double r, double d, double T, double K1, double K2, double K3, double K4);
    double pricePortfolio(double barrierLevelDown, double barrierLevelUp);

private:
    double S0, sigma, r, d, T, K1, K2, K3, K4;
};

#endif