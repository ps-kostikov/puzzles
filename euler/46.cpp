#include "common.h"

#include <iostream>
#include <set>


bool check(Natural n, const std::set<Natural>& primes)
{
    for (Natural k = 1; 2 * k * k < n; ++k) {
        if (primes.count(n - 2 * k * k) > 0) {
            return true;
        }
    }
    return false;
}


int main()
{
    PrimeGenerator gen;
    std::set<Natural> primes;
    Natural maxPrime = 1;
    for (Natural n = 3; true; n += 2) {
        while (n > maxPrime) {
            maxPrime = gen.next();
            primes.insert(maxPrime);
        }
        if (primes.count(n) > 0) {
            continue;
        }
        if (!check(n, primes)) {
            std::cout << n << std::endl;
            break;
        }
    }
    return 0;
}