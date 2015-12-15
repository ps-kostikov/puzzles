#include "common.h"

#include <iostream>


int main()
{
    int indexToFind = 1;
    int currentIndex = 0;
    int count = 0;
    int prod = 1;
    for (Natural n = 1; true; ++n) {
        auto digits = common::toDigits(n, 10);
        for (auto digit: digits) {
            ++currentIndex;
            if (currentIndex == indexToFind) {
                prod *= digit;
                ++count;
                indexToFind *= 10;
            }
        }

        if (count >= 7) {
            std::cout << prod << std::endl;
            break;
        }
    }
    return 0;
}