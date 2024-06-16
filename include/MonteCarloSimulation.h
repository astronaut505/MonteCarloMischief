#ifndef MONTE_CARLO_SIMULATION_H
#define MONTE_CARLO_SIMULATION_H

#include <vector>

class MonteCarloSimulation
{
public:
    MonteCarloSimulation(double S0, double sigma, double r, double d, double T, int numSimulations);
    std::vector<double> simulate();

private:
    double S0, sigma, r, d, T;
    int numSimulations;
};

#endif // MONTE_CARLO_SIMULATION_H
