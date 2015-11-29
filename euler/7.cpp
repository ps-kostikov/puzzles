#include "common.h"

#include <iostream>

int main()
{
    unsigned counter = 0;
    Natural lastPrime = 0;
    PrimeGenerator g;
    while (counter < 10001) {
        lastPrime = g.next();
        ++counter;
    }
    std::cout << lastPrime << std::endl;
}