#include "common.h"

#include <iostream>
#include <vector>

struct PrimeExp
{
    Natural prime;
    size_t exp;
};

typedef std::vector<PrimeExp> PrimeExps;

PrimeExps
primeReduceExp(Natural n)
{
    PrimeExps primeExps;
    if (n <= 1) {
        return primeExps;
    }
    PrimeGenerator g;
    while (true) {
        auto p = g.next();
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
}

int main()
{
    for (Natural n = 1; ;++n) {
        auto triangleNum = (n * (n + 1)) / 2;
        auto primeExps = primeReduceExp(triangleNum);
        Natural deviderCount = 1;
        for (auto primeExp: primeExps) {
            deviderCount *= (primeExp.exp + 1);
        }

        // std::cout << n << " " << triangleNum << " " << deviderCount << std::endl;
        if (deviderCount > 500) {
            std::cout << triangleNum << std::endl;
            break;
        }
    }
    return 0;
}