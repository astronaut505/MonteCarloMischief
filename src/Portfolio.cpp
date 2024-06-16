#include "Portfolio.h"
#include "OptionPricing.h"

Portfolio::Portfolio(double S0, double sigma, double r, double d, double T, double K1, double K2, double K3, double K4)
    : S0(S0), sigma(sigma), r(r), d(d), T(T), K1(K1), K2(K2), K3(K3), K4(K4) {}

double Portfolio::pricePortfolio(double barrierLevel)
{
    double price = 0.0;
    price -= downAndOutCall(S0, K1, r, T, sigma, barrierLevel);
    price += downAndOutCall(S0, K2, r, T, sigma, barrierLevel);
    price += upAndOutPut(S0, K3, r, T, sigma, barrierLevel);
    price -= upAndOutPut(S0, K4, r, T, sigma, barrierLevel);
    return price;
}
