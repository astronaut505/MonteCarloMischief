#ifndef PORTFOLIO_PRICING_H
#define PORTFOLIO_PRICING_H

#include <Rcpp.h>

Rcpp::NumericVector pricePortfolio(double S0, double sigma, double r, double d, double T,
                                   double K1, double K2, double K3, double K4, double barrierLevel);

#endif // PORTFOLIO_PRICING_H
