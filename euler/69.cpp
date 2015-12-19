#include "common.h"

#include <iostream>

int main()
{
    common::Primes primes;
    Natural limit = 1000000;
    Natural result = 1;
    for (int i = 0; true; ++i) {
        if (result * primes[i] > limit) {
            std::cout << result << std::endl;
            break;
        }
        result *= primes[i];
    }
    return 0;
}