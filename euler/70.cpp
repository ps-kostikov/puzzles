#include "common.h"

#include <iostream>
#include <algorithm>
#include <limits>

common::Primes primes;

Natural pow(Natural n, Natural e)
{
    Natural result = 1;
    for (int i = 0; i < e; ++i) {
        result *= n;
    }
    return result;
}

Natural phi(Natural n)
{
    const auto multipliers = common::factorization(n, primes);
    Natural result = 1;
    for (const auto& multiplier: multipliers) {
        std::cout << multiplier.prime << " ^ " << multiplier.exp << std::endl;
        result *= (multiplier.prime - 1);
        // result *= (pow(multiplier.prime, multiplier.exp - 1) * (multiplier.prime - 1));
    }
    return result;
}

bool check(Natural n, Natural phiN)
{
    auto strN = std::to_string(n);
    auto strPhi = std::to_string(phiN);
    // std::cout << strPhi << " " << strN << std::endl;
    std::sort(strN.begin(), strN.end());
    std::sort(strPhi.begin(), strPhi.end());
    return strN == strPhi;
}

int main()
{
    // Natural n = 783169;
    // std::cout << n << ": " << phi(n) << std::endl;
    // return 0;

    // double bestRatio = std::numeric_limits<double>::max();
    // Natural bestN = 0;
    // for (Natural n = 2; n < 1000000; ++n) {
    //     Natural phiN = phi(n);
    //     if (check(n, phiN)) {
    //         double ratio = n / static_cast<double>(phiN);
    //         if (ratio < bestRatio) {
    //             bestRatio = ratio;
    //             bestN = n;
    //         }
    //         std::cout << n << ": " << phiN << " - " << ratio << std::endl;
    //     }
    // }
    // std::cout << bestN << ": " << bestRatio << std::endl;

    double bestRatio = std::numeric_limits<double>::max();
    Natural bestN = 0;
    Natural limit = 10000000;
    for (Natural i = 1; true; ++i) {
        auto primeI = primes[i];
        if (primeI >= limit) {
            break;
        }
        for (Natural j = i; true; ++j) {
            auto primeJ = primes[j];
            if (primeI * primeJ >= limit) {
                break;
            }

            Natural n = primeI * primeJ;
            Natural phiN = 0;
            if (primeI == primeJ) {
                phiN = primeI * (primeI - 1);
            } else {
                phiN = (primeI - 1) * (primeJ - 1);
            }

            if (check(n, phiN)) {
                double ratio = n / static_cast<double>(phiN);
                if (ratio < bestRatio) {
                    bestRatio = ratio;
                    bestN = n;
                }
                // std::cout << n << ": " << phiN << " - " << ratio << std::endl;

            }
        }
    }
    std::cout << bestN << std::endl;
    return 0;
}