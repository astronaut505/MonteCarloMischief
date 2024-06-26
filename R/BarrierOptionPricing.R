#' Monte Carlo Barrier Option Pricing
#'
#' @param n_sim Number of simulations
#' @param S0 Initial stock price
#' @param K Strike price
#' @param r Risk-free rate
#' @param sigma Volatility
#' @param T Time to maturity
#' @param barrier Barrier level
#' @param is_call TRUE for call option, FALSE for put option
#' @param is_down_and_out TRUE for down-and-out, FALSE for up-and-out
#' @return Option price
#' @export
#' @examples
#' monte_carlo_barrier_option(10000, 115, 100, 0.05, 0.25, 5/12, 90, TRUE, TRUE)
#'
monte_carlo_barrier_option <- function(n_sim, S0, K, r, sigma, T, barrier, is_call, is_down_and_out) {
  .Call('_BarrierOptionPricing_monte_carlo_barrier_option', PACKAGE = 'BarrierOptionPricing', n_sim, S0, K, r, sigma, T, barrier, is_call, is_down_and_out)
}
