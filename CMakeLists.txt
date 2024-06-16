cmake_minimum_required(VERSION 3.10)
project(MonteCarloMischief)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(PortfolioPricing src/main.cpp src/MonteCarloSimulation.cpp src/OptionPricing.cpp src/Portfolio.cpp)
