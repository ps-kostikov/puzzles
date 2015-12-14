#include "common.h"

#include <iostream>


Natural powerMod(Natural n, Natural power, Natural mod)
{
    Natural result = 1;
    for (Natural i = 0; i < power; ++i) {
        result = (result * n) % mod;
    }
    return result;
}


int main()
{
    Natural sum = 0;
    Natural mod = 10000000000;
    for (Natural n = 1; n <= 1000; ++n) {
        sum = (sum + powerMod(n, n, mod)) % mod;
    }
    std::cout << sum << std::endl;
    return 0;
}