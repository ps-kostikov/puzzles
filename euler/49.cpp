#include "common.h"

#include <iostream>
#include <algorithm>

bool isPermutation(Natural n1, Natural n2)
{
    auto d1 = common::toDigits(n1, 10);
    auto d2 = common::toDigits(n2, 10);
    std::sort(d1.begin(), d1.end());
    std::sort(d2.begin(), d2.end());
    return d1 == d2;
}

int main()
{
    PrimeGenerator gen;
    Natural min = 1000;
    Natural max = 10000;
    Naturals primes;
    while (true) {
        auto prime = gen.next();
        if (prime > min and prime < max) {
            primes.push_back(prime);
        }
        if (prime > max) {
            break;
        }
    }

    auto isPrime = [&primes] (Natural n) {
        return std::binary_search(primes.begin(), primes.end(), n);
    };

    int shift = 3330;
    for (auto prime: primes) {
        auto next = prime + shift;
        auto nextNext = next + shift;

        if (not isPrime(next) or not isPrime(nextNext)) {
            continue;
        }

        if (isPermutation(prime, next) and isPermutation(next, nextNext)) {
            if (prime != 1487) {
                std::cout << prime << next << nextNext << std::endl;
            }
        }

    }
    return 0;
}