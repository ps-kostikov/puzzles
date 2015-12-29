#include "common.h"

#include <iostream>
#include <sstream>
#include <cmath>

int main()
{
    int index = 1;
    int bestIndex = 0;
    double bestLog = 0.;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int base;
        char comma;
        int exp;
        ss >> base >> comma >> exp;
        double log = std::log(static_cast<double>(base)) * exp;
        if (log > bestLog) {
            bestLog = log;
            bestIndex = index;
        }
        ++index;
    }
    std::cout << bestIndex << std::endl;
    return 0;
}