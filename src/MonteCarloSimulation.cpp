#include "MonteCarloSimulation.h"
#include <random>
#include <cmath>

MonteCarloSimulation::MonteCarloSimulation(double S0, double r, double sigma, double T, int numSimulations)
    : S0(S0), r(r), sigma(sigma), T(T), numSimulations(numSimulations) {}

std::vector<double> MonteCarloSimulation::simulate()
{
    std::vector<double> prices(numSimulations);
    std::mt19937_64 gen(std::random_device{}());
    std::normal_distribution<> dist(0, 1);

    for (int i = 0; i < numSimulations; ++i)
    {
        double ST = S0 * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * dist(gen));
        prices[i] = ST;
    }

    return prices;
}
