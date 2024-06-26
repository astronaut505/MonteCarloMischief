#include <Rcpp.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace Rcpp;

// Function to simulate a single path
double simulate_path(double S0, double r, double sigma, double T, int steps)
{
    double dt = T / steps;
    double path = S0;

    for (int i = 0; i < steps; ++i)
    {
        double Z = R::rnorm(0, 1);
        path *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
    }

    return path;
}

// [[Rcpp::export]]
double monte_carlo_barrier_option(int n_sim, double S0, double K, double r, double sigma, double T, double barrier, bool is_call, bool is_down_and_out)
{
    int steps = 100;
    double sum_payoff = 0.0;
    double discount_factor = exp(-r * T);

    for (int i = 0; i < n_sim; ++i)
    {
        bool barrier_breached = false;
        double path = S0;

        for (int j = 0; j < steps; ++j)
        {
            double Z = R::rnorm(0, 1);
            path *= exp((r - 0.5 * sigma * sigma) * (T / steps) + sigma * sqrt(T / steps) * Z);

            if (is_down_and_out && path <= barrier)
            {
                barrier_breached = true;
                break;
            }
            else if (!is_down_and_out && path >= barrier)
            {
                barrier_breached = true;
                break;
            }
        }

        if (!barrier_breached)
        {
            double payoff = is_call ? std::max(path - K, 0.0) : std::max(K - path, 0.0);
            sum_payoff += payoff;
        }
    }

    return discount_factor * (sum_payoff / n_sim);
}
