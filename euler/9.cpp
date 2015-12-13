#include "common.h"

#include <iostream>

int main()
{
    const Natural max = 1000;
    for (Natural a = 1; a < max; ++a) {
        for (Natural b = 1; a + b < max; ++b) {
            Natural c = max - a - b;
            if (a * a + b * b == c * c) {
                // std::cout << "a = " << a << std::endl;
                // std::cout << "b = " << b << std::endl;
                // std::cout << "c = " << c << std::endl;
                std::cout << a * b * c << std::endl;
                return 0;
            }
        }
    }
}