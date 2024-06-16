// src/MonteCarloSimulation.cpp

#include "../include/MonteCarloSimulation.h"
#include <random>
#include <cmath>

std::vector<double> MonteCarloSimulation::simulate()
{
    std::vector<double> prices(numSimulations);
    std::mt19937_64 gen(std::random_device{}());
    std::normal_distribution<> dist(0, 1);

    for (int i = 0; i < numSimulations; ++i)
    {
        double ST = S0 * exp((r - d - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * dist(gen));
        prices[i] = ST;
    }

    return prices;
}
