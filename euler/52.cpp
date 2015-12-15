#include "common.h"

#include <iostream>
#include <algorithm>

bool isPermutation(Natural n1, Natural n2)
{
    auto d1 = common::toDigits(n1, 10);
    auto d2 = common::toDigits(n2, 10);
    std::sort(d1.begin(), d1.end());
    std::sort(d2.begin(), d2.end());
    return d1 == d2;
}

int main()
{
    for (Natural n = 1; true; ++n) {
        bool required = true;
        for (int mult = 2; mult <= 6; ++mult) {
            if (not isPermutation(n, n * mult)) {
                required = false;
                break;
            }
        }
        if (required) {
            std::cout << n << std::endl;
            break;
        }
    }
    return 0;
}