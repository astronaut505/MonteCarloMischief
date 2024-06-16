#include "portfolio_pricing.h"
#include "Portfolio.h"

// [[Rcpp::export]]
Rcpp::NumericVector pricePortfolio(double S0, double sigma, double r, double d, double T,
                                   double K1, double K2, double K3, double K4, double barrierLevel)
{
    Portfolio portfolio(S0, sigma, r, d, T, K1, K2, K3, K4);
    double price = portfolio.pricePortfolio(barrierLevel);
    return Rcpp::NumericVector::create(price);
}
