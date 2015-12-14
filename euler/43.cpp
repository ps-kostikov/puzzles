#include "common.h"

#include <iostream>
#include <set>
#include <algorithm>

bool check(const Digits& digits)
{
    if (common::fromDigits({digits[1], digits[2], digits[3]}, 10) % 2 != 0) {
        return false;
    }
    if (common::fromDigits({digits[2], digits[3], digits[4]}, 10) % 3 != 0) {
        return false;
    }
    if (common::fromDigits({digits[3], digits[4], digits[5]}, 10) % 5 != 0) {
        return false;
    }
    if (common::fromDigits({digits[4], digits[5], digits[6]}, 10) % 7 != 0) {
        return false;
    }
    if (common::fromDigits({digits[5], digits[6], digits[7]}, 10) % 11 != 0) {
        return false;
    }
    if (common::fromDigits({digits[6], digits[7], digits[8]}, 10) % 13 != 0) {
        return false;
    }
    if (common::fromDigits({digits[7], digits[8], digits[9]}, 10) % 17 != 0) {
        return false;
    }
    return true;
}

int main()
{
    Natural sum = 0;
    Digits digits{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        if (check(digits)) {
            auto n = common::fromDigits(digits, 10);
            // std::cout << n << std::endl;
            sum += n;
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    std::cout << sum << std::endl;
    return 0;
}