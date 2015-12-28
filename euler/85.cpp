#include "common.h"

#include <iostream>
#include <cmath>
#include <limits>

Natural f(Natural x, Natural y)
{
    return (x * (x + 1) * y * (y + 1)) / 4;
}


int main()
{
    Natural bestDiff = std::numeric_limits<Natural>::max();
    Natural bestX = 0;
    Natural bestY = 0;
    for (Natural x = 1; x < 2000; ++x) {
        double y = (std::sqrt(1 + 32000000. / (x * (x + 1))) - 1) / 2.;
        for (int intY: {std::floor(y), std::ceil(y)}) {
            auto diff = std::abs(static_cast<long long>(f(x, intY)) - 2000000);
            if (diff < bestDiff) {
                bestDiff = diff;
                bestX = x;
                bestY = intY;
            }
        }
    }
    // std::cout << bestDiff << ": " << bestX << ", " << bestY << "| " << bestX * bestY << std::endl;
    std::cout << bestX * bestY << std::endl;
    return 0;
}