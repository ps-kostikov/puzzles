#include "common.h"

PrimeGenerator::PrimeGenerator(): current_{} {}

Natural
PrimeGenerator::next()
{
    if (current_.empty()) {
        current_.push_back(2);
        return 2;
    }
    Natural prev = max();
    while (true) {
        Natural toTry = prev + 1;
        bool prime = true;
        for (auto p: current_) {
            if (p * p > toTry) {
                break;
            }
            if (!(toTry % p)) {
                prime = false;
                break;
            }
        }
        if (prime) {
            current_.push_back(toTry);
            return toTry;
        }
        prev = toTry;
    }
}

Naturals
PrimeGenerator::all() const
{
    return current_;
}

Natural
PrimeGenerator::max() const
{
    return current_.back();
}


Naturals
primeReduce(Natural n)
{
    Naturals primes;
    if (n <= 1) {
        return primes;
    }
    PrimeGenerator g;
    while (true) {
        auto p = g.next();
        while (!(n % p)) {
            primes.push_back(p);
            n /= p;
        }
        if (n == 1) {
            return primes;
        }
    }
}
