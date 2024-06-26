#include <Rcpp.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace Rcpp;

// Function to simulate a single path and return average price
double simulate_path_arithmetic_asian(double S0, double r, double sigma, double T, int steps, double barrier, bool is_down_and_out)
{
    double dt = T / steps;
    double path = S0;
    double sum_prices = S0;

    for (int i = 1; i <= steps; ++i)
    {
        double Z = R::rnorm(0, 1);
        path *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        sum_prices += path;

        // Check for barrier
        if (is_down_and_out && path <= barrier)
        {
            return 0.0; // Path breached the barrier
        }
        else if (!is_down_and_out && path >= barrier)
        {
            return 0.0; // Path breached the barrier
        }
    }

    return sum_prices / (steps + 1); // Return average price for arithmetic Asian option
}

// [[Rcpp::export]]
double monte_carlo_arithmetic_asian(int n_sim, double S0, double K, double r, double sigma, double T, double barrier, bool is_call, bool is_down_and_out)
{
    int steps = 100;
    double sum_payoff = 0.0;
    double discount_factor = exp(-r * T);

    for (int i = 0; i < n_sim; ++i)
    {
        double average_price = simulate_path_arithmetic_asian(S0, r, sigma, T, steps, barrier, is_down_and_out);
        if (average_price > 0)
        { // Only consider paths that didn't breach the barrier
            double payoff = is_call ? std::max(average_price - K, 0.0) : std::max(K - average_price, 0.0);
            sum_payoff += payoff;
        }
    }

    return discount_factor * (sum_payoff / n_sim);
}
