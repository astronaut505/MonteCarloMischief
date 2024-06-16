#include "../include/MonteCarloSimulation.h"
#include <random>
#include <cmath>

MonteCarloSimulation::MonteCarloSimulation(double S0, double sigma, double r, double d, double T, int numSimulations)
    : S0(S0), sigma(sigma), r(r), d(d), T(T), numSimulations(numSimulations) {}

std::vector<double> MonteCarloSimulation::simulate()
{
    std::vector<double> prices(numSimulations);
    std::mt19937_64 gen(std::random_device{}());
    std::normal_distribution<> dist(0, 1); // Correctly create a normal distribution object

    for (int i = 0; i < numSimulations; ++i)
    {
        double ST = S0 * exp((r - d - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * dist(gen)); // Correctly call the distribution
        prices[i] = ST;
    }

    return prices;
}
