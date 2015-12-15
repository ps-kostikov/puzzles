#include "common.h"

#include <iostream>
#include <set>
#include <algorithm>

Natural eval(Natural mult, Natural n)
{
    Digits digits;
    for (Natural i = 1; i <= n; ++i) {
        for (auto d: common::toDigits(mult * i, 10)) {
            digits.push_back(d);
        }
    }
    return common::fromDigits(digits, 10);
}

bool check(const Digits& digits)
{
    auto value = common::fromDigits(digits, 10);
    for (int firstSize = 1; firstSize < digits.size(); ++firstSize) {
        Digits firstDigits(digits.begin(), digits.begin() + firstSize);
        auto mult = common::fromDigits(firstDigits, 10);
        for (int n = 2; true; ++n) {
            auto cand = eval(mult, n);
            if (cand == value) {
                return true;
            }
            if (cand > value) {
                break;
            }
        }
    }
    return false;
}

bool cmp(const Digit &dLeft, const Digit &dRight)
{
    return dLeft > dRight;
}

int main()
{
    Digits digits{9, 8, 7, 6, 5, 4, 3, 2, 1};
    do {
        if (check(digits)) {
            std::cout << common::fromDigits(digits, 10) << std::endl;
            break;
        }
    } while (std::next_permutation(digits.begin(), digits.end(), cmp));
    return 0;
}