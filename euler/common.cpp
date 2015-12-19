#include "common.h"

#include <algorithm>

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

Natural GCD(Natural a, Natural b)
{
    int max = std::max(a, b);
    int min = std::min(a, b);
    if (min == 0) {
        return 0;
    }
    if (max % min == 0) {
        return min;
    }
    return GCD(min, max - min * (max / min));
}

namespace common {

Primes::Primes()
{}

Natural Primes::operator[](Natural index)
{
    while (index >= all_.size()) {
        genNext();
    }
    return all_[index];
}

bool Primes::contain(Natural n)
{
    while (all_.empty() or *all_.rbegin() < n) {
        genNext();
    }
    return std::binary_search(all_.begin(), all_.end(), n);
}

void
Primes::genNext()
{
    if (all_.empty()) {
        all_.push_back(2);
        return;
    }
    Natural prev = *all_.rbegin();
    while (true) {
        Natural toTry = prev + 1;
        bool prime = true;
        for (auto p: all_) {
            if (p * p > toTry) {
                break;
            }
            if (!(toTry % p)) {
                prime = false;
                break;
            }
        }
        if (prime) {
            all_.push_back(toTry);
            return;
        }
        prev = toTry;
    }
}


Digits toDigits(Natural n, Natural base)
{
    auto tmp = n;
    Digits result;
    while (tmp > 0) {
        result.push_back(tmp % base);
        tmp /= base;
    }
    return Digits(result.rbegin(), result.rend());
}

Natural fromDigits(const Digits& digits, Natural base)
{
    Natural result = 0;
    for (auto it = digits.begin(); it < digits.end(); ++it) {
        result = result * base + *it;
    }
    return result;
}

} // namespace common
