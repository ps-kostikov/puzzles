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
