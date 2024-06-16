#' Price Portfolio
#'
#' @param S0 Initial stock price
#' @param sigma Volatility
#' @param r Risk-free rate
#' @param d Dividend yield
#' @param T Time to maturity
#' @param K1 Strike price for the first call
#' @param K2 Strike price for the second call
#' @param K3 Strike price for the first put
#' @param K4 Strike price for the second put
#' @param barrierLevelDown Barrier level for down-and-out options
#' @param barrierLevelUp Barrier level for up-and-out options
#' @export
price_portfolio <- function(S0, sigma, r, d, T, K1, K2, K3, K4, barrierLevelDown, barrierLevelUp) {
  .Call('_portfolio_price_portfolio', S0, sigma, r, d, T, K1, K2, K3, K4, barrierLevelDown, barrierLevelUp)
}