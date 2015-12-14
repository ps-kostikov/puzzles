#include "common.h"

#include <iostream>
#include <set>
#include <algorithm>

int fromDigits(Digits::const_iterator begin, Digits::const_iterator end)
{
    int result = 0;
    for (auto it = begin; it < end; ++it) {
        result = result * 10 + *it;
    }
    return result;
}

bool cmp(const Digit &dLeft, const Digit &dRight)
{
    return dLeft > dRight;
}

int main()
{
    PrimeGenerator gen;
    std::set<int> primes;
    Digits digits{7, 6, 5, 4, 3, 2, 1};
    while (true) {
        auto prime = gen.next();
        if (prime >= 7654321) {
            break;
        }
        primes.insert(prime);
    }
    do {
        auto n = fromDigits(digits.begin(), digits.end());
        if (primes.count(n) > 0) {
            std::cout << n << std::endl;
            return 0;
        }
    } while (std::next_permutation(digits.begin(), digits.end(), cmp));
    return 0;
}