#include "common.h"

#include <iostream>


int main()
{
    Natural count = 0;
    for (Natural d = 2; d <= 12000; ++d) {
        for (Natural n = 1; n < d; ++n) {
            if (n * 2 >= d) {
                break;
            }
            if (n * 3 > d) {
                if (GCD(n, d) == 1) {
                    ++count;
                }
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}