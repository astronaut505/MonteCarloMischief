# Define R wrapper function
price_portfolio <- function(S0, sigma, r, d, T, K1, K2, K3, K4, barrierLevelDown, barrierLevelUp) {
    .Call('_portfolio_price_portfolio', PACKAGE = 'portfolio', S0, sigma, r, d, T, K1, K2, K3, K4, barrierLevelDown, barrierLevelUp)
}
