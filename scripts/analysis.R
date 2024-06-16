setwd("~/GitHub/MonteCarloMischief/scripts")
library(ggplot2)

# Load the Rcpp package
library(Rcpp)
sourceCpp("../R/portfolio_pricing.cpp")


# Define the parameters
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
  as.numeric(price_portfolio(s, sigma, r, d, t, k1, k2, k3, k4, b))
}, results$s, results$b)

# Print first few rows of results to verify
print(head(results))

# Create the plot
ggplot(results, aes(x = s, y = b, fill = price)) +
  geom_tile() +
  scale_fill_gradient(low = "blue", high = "red") +
  labs(title = "Portfolio Price Heatmap",
       x = "Underlying Price",
       y = "Barrier Level",
       fill = "Portfolio Price") +
  theme_minimal()

# Define the output file path
output_file <- "../data/simulation_results.csv"

# Ensure the directory exists
if (!dir.exists(dirname(output_file))) {
  dir.create(dirname(output_file), recursive = TRUE)
}

# Write results to CSV
write.csv(results, output_file, row.names = FALSE)

# Print a message confirming the write
cat("Results written to", output_file, "\n")

