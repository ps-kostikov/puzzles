#pragma once

#include <vector>

typedef unsigned long long Natural;
typedef std::vector<Natural> Naturals;
typedef unsigned int Digit;
typedef std::vector<Digit> Digits;

class PrimeGenerator
{
public:
    PrimeGenerator();

    Natural next();
    Naturals all() const;
    Natural max() const;

private:
    Naturals current_;
};

Naturals primeReduce(Natural n);

Natural GCD(Natural a, Natural b);

namespace common {

class Primes
{
public:
    Primes();

    Natural operator[](Natural index);
    bool contain(Natural n);

private:
    void genNext();
    Naturals all_;
};

struct PrimeMuliplier
{
    Natural prime;
    Natural exp;
};

std::vector<PrimeMuliplier> factorization(Natural n, Primes& primes);

Digits toDigits(Natural n, Natural base);

Natural fromDigits(const Digits& digits, Natural base);

} // namespace common
