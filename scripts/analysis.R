# Analysis.R

library(portfolio)
library(ggplot2)

# Define parameters
s0 <- 115
sigma <- 0.25
r <- 0.05
d <- 0.0
t <- 5 / 12
k1 <- 100
k2 <- 110
k3 <- 120
k4 <- 130

# Define the ranges for underlying price and barrier level
underlying_prices <- seq(100, 130, by = 1)
barrier_levels <- seq(90, 115, by = 1)

# Perform simulations
results <- expand.grid(s = underlying_prices, b = barrier_levels)
results$price <- mapply(function(s, b) {
  as.numeric(price_portfolio(s, sigma, r, d, t, k1, k2, k3, k4, s * 0.8, s * 1.2)) # nolint
}, results$s, results$b)

# Create the plot
ggplot(results, aes(x = s, y = b, fill = price)) +
  geom_tile() +
  scale_fill_gradient(low = "blue", high = "red") +
  labs(title = "Portfolio Price Heatmap",
       x = "Underlying Price",
       y = "Barrier Level",
       fill = "Portfolio Price") +
  theme_minimal()

# Save the results
write.csv(results, "data/simulation_results.csv", row.names = FALSE)
