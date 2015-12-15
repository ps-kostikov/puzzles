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

        Natural sum = 0;
        for (size_t i = left; i < primes.size(); ++i) {
            sum += primes[i];
            if (sum > max) {
                break;
            }

            auto len = i - left + 1;
            if (len > bestLen) {
                if (std::binary_search(primes.begin(), primes.end(), sum)) {
                    bestLen = len;
                    bestPrime = sum;
                }
            }
        }
    }
    std::cout << bestPrime << std::endl;
    return 0;
}