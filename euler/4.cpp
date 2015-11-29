#include "common.h"

#include <iostream>
#include <cmath>
#include <vector>

Digits
fetchDigits(Natural n, size_t base = 10)
{
    Digits digits;
    while (n > 0) {
        digits.push_back(n % base);
        n /= base;
    }
    return digits;
}

bool
isPalindrom(Natural n)
{
    auto digits = fetchDigits(n);
    Digits reverse(digits.rbegin(), digits.rend());
    return reverse == digits;
}

int main()
{
    Natural res = 0;
    for (Natural n = 0; n < 1000; ++n) {
        for (Natural k = 0; k < 1000; ++k) {
            auto prod = n * k;
            if (isPalindrom(n * k)) {
                res = std::max(res, n * k);
            }
        }
    }
    std::cout << res << std::endl;
}