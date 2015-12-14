#include "common.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


bool checkRightToLeft(int prime, const std::set<int>& allPrimes)
{
    int tmp = prime;
    while (tmp > 0) {
        if (allPrimes.count(tmp) == 0) {
            return false;
        }
        tmp /= 10;
    }
    return true;
}


bool checkLeftToRight(int prime, const std::set<int>& allPrimes)
{
    for (int mult = 10; mult < prime; mult *= 10) {
        if (allPrimes.count(prime % mult) == 0) {
            return false;
        }
    }
    return true;
}

bool check(int prime, const std::set<int>& allPrimes)
{
    if (prime < 10) {
        return false;
    }
    return checkLeftToRight(prime, allPrimes) and checkRightToLeft(prime, allPrimes);
}

int main()
{
    PrimeGenerator primeGen;
    std::set<int> primes;
    std::vector<int> requiredPrimes;
    while (true) {
        auto prime = primeGen.next();
        primes.insert(prime);
        if (check(prime, primes)) {
            requiredPrimes.push_back(prime);
            if (requiredPrimes.size() >= 11) {
                break;
            }
        }
    }

    int sum = 0;
    for (auto prime: requiredPrimes) {
        sum += prime;
        // std::cout << prime << " ";
    }
    // std::cout << std::endl;

    std::cout << sum << std::endl;
    return 0;
}
