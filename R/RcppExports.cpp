// RcppExports.cpp

#include <Rcpp.h>
#include "../include/Portfolio.h"

// [[Rcpp::export]]
Rcpp::NumericVector price_portfolio(double S0, double sigma, double r, double d, double T,
                                    double K1, double K2, double K3, double K4, double barrierLevelDown, double barrierLevelUp)
{
    Portfolio portfolio(S0, sigma, r, d, T, K1, K2, K3, K4);
    double price = portfolio.pricePortfolio(barrierLevelDown, barrierLevelUp);
    return Rcpp::NumericVector::create(price);
}