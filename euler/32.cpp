#include <iostream>
#include <set>
#include <algorithm>

#include "common.h"

Natural fromDigits(Digits::const_iterator begin, Digits::const_iterator end)
{
    Natural result = 0;
    for (auto it = begin; it < end; ++it) {
        result = result * 10 + *it;
    }
    return result;
}

std::set<Natural> findProducts(const Digits digits)
{
    std::set<Natural> result;
    for (size_t mulOneEnd = 1; mulOneEnd < digits.size(); ++mulOneEnd) {
        for (size_t mulTwoEnd = mulOneEnd + 1; mulTwoEnd < digits.size(); ++mulTwoEnd) {
            auto mulOne = fromDigits(digits.begin(), digits.begin() + mulOneEnd);
            auto mulTwo = fromDigits(digits.begin() + mulOneEnd, digits.begin() + mulTwoEnd);
            auto prod = fromDigits(digits.begin() + mulTwoEnd, digits.end());
            if (mulOne * mulTwo == prod) {
                // std::cout << mulOne << " * " << mulTwo << " = " << prod << std::endl;
                result.insert(prod);
            }
        }
    }
    return result;
}

int main()
{
    // Digits digits{3, 9, 1, 8, 6, 7, 2, 5, 4};
    Digits digits;
    for (Digit d = 1; d <= 9; ++d) {
        digits.push_back(d);
    }
    // std::set<Natural> products = findProducts(digits);
    std::set<Natural> products;
    do {
        auto localProducts = findProducts(digits);
        products.insert(localProducts.begin(), localProducts.end());
    } while (std::next_permutation(digits.begin(), digits.end()));
    // for (auto prod: products) {
    //     std::cout << prod << std::endl;
    // }
    Natural sum = 0;
    for (auto prod: products) {
        sum += prod;
    }
    std::cout << sum << std::endl;
    return 0;
}