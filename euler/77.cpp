#include "common.h"

#include <iostream>
#include <algorithm>
#include <map>

std::map<std::pair<Natural, Natural>, Natural> cache;
common::Primes primes;

Natural f(Natural n, Natural maxPart)
{
    std::pair<Natural, Natural> key(n, maxPart);
    if (cache.count(key) > 0) {
        return cache[key];
    }
    if (n == 0) {
        return 1;
    }

    Natural total = 0;
    for (int i = 0; true; ++i) {
        auto prime = primes[i];
        if (prime > n or prime > maxPart) {
            break;
        }
        total += f(n - prime, prime);
    }

    cache[key] = total;
    // std::cout << "n = " << n << "; max part = " << maxPart << "; total = " << total << std::endl;
    return total;
}

Natural p(Natural n)
{
    return f(n, n);
}

int main()
{
    for (Natural n = 2; true ; ++n) {
        auto pn = p(n);
        // std::cout << n << ": " << pn << std::endl;
        if (pn > 5000) {
            std::cout << n << std::endl;
            break;
        }
    }
    return 0;
}