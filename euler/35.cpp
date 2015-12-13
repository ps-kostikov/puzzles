#include "common.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


int firstDigitMult(int n) {
    int mult = 1;
    while (true) {
        n /= 10;
        if (n == 0) {
            return mult;
        }
        mult *= 10;
    }
}

std::vector<int> allRotations(int n) {
    std::vector<int> result;
    int mult = firstDigitMult(n);
    int tmp = n;
    do {
        result.push_back(tmp);
        auto lastDigit = tmp % 10;
        tmp = tmp / 10 + lastDigit * mult;
    } while (tmp != n);
    return result;
}

bool check(int prime, const std::set<int>& allPrimes)
{
    for (auto n: allRotations(prime)) {
        if (allPrimes.count(n) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    PrimeGenerator primeGen;
    std::set<int> primes;
    while (true) {
        auto prime = primeGen.next();
        if (prime >= 1000000) {
            break;
        }
        primes.insert(prime);
    }

    int count = 0;
    for (auto prime: primes) {
        if (check(prime, primes)) {
            // std::cout << prime << " ";
            ++count;
        }
    }
    // std::cout << std::endl;

    std::cout << count << std::endl;
    return 0;
}
