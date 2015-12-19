#include "common.h"

#include <iostream>
#include <cmath>
#include <algorithm>


int main()
{
    Natural current = 1;
    Natural totalCount = 1;
    Natural primeCount = 0;
    common::Primes primes;
    int k = 1;
    for (; true; ++k) {
        for (int i = 1; i <= 4; ++i) {
            current += 2 * k;
            ++totalCount;
            if (primes.contain(current)) {
                ++primeCount;
            }
        }
        // std::cout << current << ": " << primeCount / static_cast<double>(totalCount) << std::endl;
        if (primeCount / static_cast<double>(totalCount) < .1) {
            break;
        }
    }
    std::cout << k * 2 + 1 << std::endl;
    return 0;
}