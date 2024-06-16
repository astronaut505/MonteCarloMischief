#ifndef OPTIONPRICING_H
#define OPTIONPRICING_H

double downAndOutCall(double S, double K, double r, double T, double sigma, double B);
double upAndOutPut(double S, double K, double r, double T, double sigma, double B);

#endif // OPTIONPRICING_H
