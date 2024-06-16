#ifndef OPTION_PRICING_H
#define OPTION_PRICING_H

double downAndOutCall(double S, double K, double r, double T, double sigma, double B);
double upAndOutPut(double S, double K, double r, double T, double sigma, double B);

#endif // OPTION_PRICING_H
