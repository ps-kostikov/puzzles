#include <iostream>
#include <vector>
#include <algorithm>

#include "common.h"



int main()
{
    PrimeGenerator primeGenerator;
    Natural limit = 10000000000;
    for (int n = 1; true; ++n) {
        auto prime = primeGenerator.next();
        if (n % 2 == 0) {
            continue;
        }
        if (2 * n * prime > limit) {
            std::cout << n << ": " << prime << std::endl;
            return 0;
        }
    }
    return 0;
}