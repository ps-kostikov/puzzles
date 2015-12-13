#include "common.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


std::vector<int> toDigits(int n, int base)
{
    int tmp = n;
    std::vector<int> result;
    while (tmp > 0) {
        result.push_back(tmp % base);
        tmp /= base;
    }
    return result;
}

bool isPalindromic(int n, int base)
{
    auto digits = toDigits(n, base);
    std::vector<int> reverseDigits(digits.rbegin(), digits.rend());
    return digits == reverseDigits;
}

int main()
{
    int sum = 0;
    for (int i = 1; i < 1000000; ++i) {
        if (isPalindromic(i, 2) and isPalindromic(i, 10)) {
            // std::cout << i << " ";
            sum += i;
        }
    }
    // std::cout << std::endl;
    std::cout << sum << std::endl;
    return 0;
}
