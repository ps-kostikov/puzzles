#include "common.h"

#include <iostream>

int main()
{
    Natural n = 100;
    Natural s1 = 0;
    Natural s2 = 0;
    for (Natural k = 0; k <= n; ++k) {
        s1 += k;
        s2 += k * k;
    }
    std::cout << s1 * s1 - s2 << std::endl;
    return 0;
}