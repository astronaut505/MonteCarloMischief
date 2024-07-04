library(devtools)
Rcpp::compileAttributes("C:/Users/Me/Documents/GitHub/MonteCarloMischief")
document("C:/Users/Me/Documents/GitHub/MonteCarloMischief")
build("C:/Users/Me/Documents/GitHub/MonteCarloMischief")

install.packages("C:/Users/Me/Documents/GitHub/MonteCarloMischief/BarrierOptionPricing_0.1.0.tar.gz", repos = NULL, type = "source")
