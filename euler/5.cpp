#include "common.h"

#include <iostream>

int main()
{
    Natural n = 1;
    while (true) {
        bool correct = true;
        for (Natural d = 2; d <= 20; ++d) {
            if (n % d) {
                correct = false;
                break;
            }
        }
        if (correct) {
            std::cout << n << std::endl;
            break;
        }
        ++n;
    }
    return 0;
}