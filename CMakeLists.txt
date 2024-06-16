cmake_minimum_required(VERSION 3.10)
project(MonteCarloMischief)

set(CMAKE_CXX_STANDARD 17)

# Add R and Rcpp include directories
include_directories(include "C:/Program Files/R/R-4.3.1/include" "C:/Libraries/Rcpp/include")

add_executable(PortfolioPricing src/main.cpp src/MonteCarloSimulation.cpp src/OptionPricing.cpp src/Portfolio.cpp)
