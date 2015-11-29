#include "common.h"

#include <iostream>

int main()
{
    Natural sum = 0;
    PrimeGenerator gen;
    while (true) {
        auto prime = gen.next();
        if (prime >= 2000000) {
            break;
        }
        std::cout << prime << std::endl;
        sum += prime;
    }
    std::cout << sum << std::endl;
}