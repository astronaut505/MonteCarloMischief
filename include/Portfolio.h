#ifndef PORTFOLIO_H
#define PORTFOLIO_H

class Portfolio
{
public:
    Portfolio(double S0, double sigma, double r, double d, double T, double K1, double K2, double K3, double K4);
    double pricePortfolio(double barrierLevelDown, double barrierLevelUp);

private:
    double S0;
    double sigma;
    double r;
    double d;
    double T;
    double K1;
    double K2;
    double K3;
    double K4;
};

#endif // PORTFOLIO_H
