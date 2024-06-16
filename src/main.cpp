// src/main.cpp
#include <iostream>
#include "../include/Portfolio.h"
#include <vector>

void analyzeS0();
void analyzeSigmaAndT();

int main()
{
    analyzeS0();
    analyzeSigmaAndT();
    return 0;
}

void analyzeS0()
{
    double sigma = 0.25;
    double r = 0.05;
    double d = 0.0;
    double T = 5.0 / 12.0;
    double K1 = 100;
    double K2 = 110;
    double K3 = 120;
    double K4 = 130;

    std::vector<double> S0_values = {100, 105, 110, 115, 120, 125, 130};
    for (double S0 : S0_values)
    {
        Portfolio portfolio(S0, sigma, r, d, T, K1, K2, K3, K4);
        double barrierLevelDown = S0 * 0.8; // Barrier level for down-and-out call
        double barrierLevelUp = S0 * 1.2;   // Barrier level for up-and-out put

        double price = portfolio.pricePortfolio(barrierLevelDown, barrierLevelUp);
        std::cout << "S0: " << S0 << ", Portfolio price: " << price << std::endl;

        // Additional checks to print individual option prices
        double call1 = downAndOutCall(S0, K1, r, T, sigma, barrierLevelDown);
        double call2 = downAndOutCall(S0, K2, r, T, sigma, barrierLevelDown);
        double put1 = upAndOutPut(S0, K3, r, T, sigma, barrierLevelUp);
        double put2 = upAndOutPut(S0, K4, r, T, sigma, barrierLevelUp);

        std::cout << "Down-and-Out Call 1 price: " << call1 << std::endl;
        std::cout << "Down-and-Out Call 2 price: " << call2 << std::endl;
        std::cout << "Up-and-Out Put 1 price: " << put1 << std::endl;
        std::cout << "Up-and-Out Put 2 price: " << put2 << std::endl;

        // Verify the signs and positions
        std::cout << "Verification Sum: " << (-call1 + call2 + put1 - put2) << std::endl;
    }
}

void analyzeSigmaAndT()
{
    double S0 = 115;
    double r = 0.05;
    double d = 0.0;
    double K1 = 100;
    double K2 = 110;
    double K3 = 120;
    double K4 = 130;

    std::vector<double> sigma_values = {0.15, 0.25, 0.35};
    std::vector<double> T_values = {3.0 / 12.0, 5.0 / 12.0, 7.0 / 12.0};

    for (double sigma : sigma_values)
    {
        for (double T : T_values)
        {
            Portfolio portfolio(S0, sigma, r, d, T, K1, K2, K3, K4);
            double barrierLevelDown = S0 * 0.8; // Barrier level for down-and-out call
            double barrierLevelUp = S0 * 1.2;   // Barrier level for up-and-out put

            double price = portfolio.pricePortfolio(barrierLevelDown, barrierLevelUp);
            std::cout << "Sigma: " << sigma << ", T: " << T << ", Portfolio price: " << price << std::endl;

            // Additional checks to print individual option prices
            double call1 = downAndOutCall(S0, K1, r, T, sigma, barrierLevelDown);
            double call2 = downAndOutCall(S0, K2, r, T, sigma, barrierLevelDown);
            double put1 = upAndOutPut(S0, K3, r, T, sigma, barrierLevelUp);
            double put2 = upAndOutPut(S0, K4, r, T, sigma, barrierLevelUp);

            std::cout << "Down-and-Out Call 1 price: " << call1 << std::endl;
            std::cout << "Down-and-Out Call 2 price: " << call2 << std::endl;
            std::cout << "Up-and-Out Put 1 price: " << put1 << std::endl;
            std::cout << "Up-and-Out Put 2 price: " << put2 << std::endl;

            // Verify the signs and positions
            std::cout << "Verification Sum: " << (-call1 + call2 + put1 - put2) << std::endl;
        }
    }
}
