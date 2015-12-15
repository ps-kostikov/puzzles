#include "common.h"

#include <iostream>
#include <algorithm>


int main()
{
    PrimeGenerator gen;
    Natural max = 1000000;
    while (gen.next() < max);
    auto primes = gen.all();
    primes.pop_back();

    Natural bestLen = 0;
    Natural bestPrime = 0;
    for (size_t left = 0; left < primes.size(); ++left) {
        if (primes[left] * bestLen > max) {
            continue;
        }

        for (size_t right = left + 1; right < primes.size(); ++right) {
            auto len = right - left;
            if (len <= bestLen) {
                continue;
            }

            Natural sum = 0;
            bool breaked = false;
            for (Natural i = left; i < right; ++i) {
                sum += primes[i];
                if (sum > max) {
                    breaked = true;
                    break;
                }
            }
            if (breaked) {
                continue;
            }

            if (std::binary_search(primes.begin(), primes.end(), sum)) {
                bestLen = len;
                bestPrime = sum;
            }
        }
    }
    std::cout << bestPrime << std::endl;
    return 0;
}