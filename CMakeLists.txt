cmake_minimum_required(VERSION 3.10)
project(PortfolioPricing)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(PortfolioPricing
    src/main.cpp
    src/MonteCarloSimulation.cpp
    src/OptionPricing.cpp
    src/Portfolio.cpp
)
