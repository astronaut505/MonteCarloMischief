#include "OptionPricing.h"
#include <cmath>
#include <algorithm>

double downAndOutCall(double S, double K, double r, double T, double sigma, double B)
{
    if (S <= B)
        return 0.0;
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return S * exp(-r * T) * (0.5 + 0.5 * erf(d1 / sqrt(2))) - K * exp(-r * T) * (0.5 + 0.5 * erf(d2 / sqrt(2)));
}

double upAndOutPut(double S, double K, double r, double T, double sigma, double B)
{
    if (S >= B)
        return 0.0;
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return K * exp(-r * T) * (0.5 + 0.5 * erf(-d2 / sqrt(2))) - S * exp(-r * T) * (0.5 + 0.5 * erf(-d1 / sqrt(2)));
}
