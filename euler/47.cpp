#include "common.h"

#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <stdexcept>

struct PrimeExp
{
    Natural prime;
    size_t exp;
};

typedef std::vector<PrimeExp> PrimeExps;

PrimeExps
primeReduceExp(Natural n, PrimeGenerator& primeGenerator)
{
    PrimeExps primeExps;
    if (n <= 1) {
        return primeExps;
    }
    while (primeGenerator.max() < n) {
        primeGenerator.next();
    }
    for (auto p: primeGenerator.all()) {
        size_t exp = 0;
        while (!(n % p)) {
            ++exp;
            n /= p;
        }
        if (exp != 0) {
            primeExps.push_back(PrimeExp{p, exp});
        }
        if (n == 1) {
            return primeExps;
        }
    }
    throw std::runtime_error("error in prime reduce");
}

int main()
{
    const Natural seqLength = 4;
    PrimeGenerator primeGenerator;
    primeGenerator.next();
    size_t matchCount = 0;
    for (Natural n = 2; true; ++n) {
        if (primeReduceExp(n, primeGenerator).size() == seqLength) {
            ++matchCount;
        } else {
            matchCount = 0;
        }
        if (matchCount == seqLength) {
            std::cout << n + 1 - seqLength << std::endl;
            // for (Natural i = n - seqLength + 1; i <= n; ++i) {
            //     std::cout << i << " ";
            // }
            // std::cout << std::endl;
            break;
        }
    }
    return 0;
}