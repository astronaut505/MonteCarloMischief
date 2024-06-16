#ifndef MONTECARLOSIMULATION_H
#define MONTECARLOSIMULATION_H

#include <vector>

class MonteCarloSimulation
{
public:
    MonteCarloSimulation(double S0, double r, double sigma, double T, int numSimulations);
    std::vector<double> simulate();

private:
    double S0;
    double r;
    double sigma;
    double T;
    int numSimulations;
};

#endif // MONTECARLOSIMULATION_H
