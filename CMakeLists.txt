cmake_minimum_required(VERSION 3.10)
project(MonteCarloMischief)

set(CMAKE_CXX_STANDARD 17)

# Add R and Rcpp include directories
include_directories(include "C:/Program Files/R/R-4.3.1/include" "C:/Libraries/Rcpp/include")

# Add library
add_library(portfolio SHARED
    src/MonteCarloSimulation.cpp
    src/OptionPricing.cpp
    src/Portfolio.cpp
    src/RcppExports.cpp
    src/portfolio_pricing.cpp
)

# Link R and Rcpp libraries
target_link_libraries(portfolio "C:/Program Files/R/R-4.3.1/bin/x64/R.dll")
