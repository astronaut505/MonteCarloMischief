# Load the package
install.packages("Rcpp")
library(BarrierOptionPricing)
library("Rcpp")

# Test the function with some sample parameters
n_sim <- 10000
S0 <- 115
K <- 100
r <- 0.05
sigma <- 0.25
T <- 5 / 12  # 5 months
barrier <- 90
is_call <- TRUE
is_down_and_out <- TRUE

# Calculate the option price
price <- monte_carlo_arithmetic_asian(n_sim, S0, K, r, sigma, T, barrier, is_call, is_down_and_out)
print(price)

# Function to calculate the portfolio value for short call condor strategy
calculate_condor_portfolio_value <- function(S, barrier, n_sim, r, sigma, T) {
  short_deep_itm_call <- -monte_carlo_arithmetic_asian(n_sim, S, 0.8 * S, r, sigma, T, barrier, TRUE, TRUE)
  long_itm_call <- monte_carlo_arithmetic_asian(n_sim, S, 0.9 * S, r, sigma, T, barrier, TRUE, TRUE)
  long_otm_call <- monte_carlo_arithmetic_asian(n_sim, S, 1.1 * S, r, sigma, T, barrier, TRUE, TRUE)
  short_deep_otm_call <- -monte_carlo_arithmetic_asian(n_sim, S, 1.2 * S, r, sigma, T, barrier, TRUE, TRUE)

  return(short_deep_itm_call + long_itm_call + long_otm_call + short_deep_otm_call)
}

# Test the portfolio calculation
portfolio_value <- calculate_condor_portfolio_value(S0, barrier, n_sim, r, sigma, T)
print(portfolio_value)

# Parameters for visualization
barrier_levels <- seq(0.7 * S0, 1.3 * S0, by = 5)
underlying_prices <- seq(0.8 * S0, 1.2 * S0, by = 5)

# Calculate portfolio values for visualization
results <- expand.grid(underlying_price = underlying_prices, barrier_level = barrier_levels)
results$portfolio_value <- mapply(calculate_condor_portfolio_value, results$underlying_price, results$barrier_level, MoreArgs = list(n_sim = n_sim, r = r, sigma = sigma, T = T))

# Plot the results
library(ggplot2)
ggplot(results, aes(x = underlying_price, y = portfolio_value, color = as.factor(barrier_level))) +
  geom_line() +
  labs(title = "Condor Portfolio Value vs Underlying Price and Barrier Level",
       x = "Underlying Price",
       y = "Portfolio Value",
       color = "Barrier Level") +
  theme_minimal()

