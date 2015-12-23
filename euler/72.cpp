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
        result *= (pow(multiplier.prime, multiplier.exp - 1) * (multiplier.prime - 1));
    }
    return result;
}

int main()
{
    Natural sum = 0;
    for (Natural n = 2; n <= 1000000; ++n) {
        sum += phi(n);
        // std::cout << n << " " << phi(n) << std::endl;
    }

    std::cout << sum << std::endl;
    return 0;
}