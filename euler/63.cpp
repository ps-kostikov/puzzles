#include <iostream>
#include <cmath>


int main()
{
    int count = 0;
    for (int a = 1; a <= 9; ++a) {
        double l = std::log10(static_cast<double>(a));
        for (int n = 1; true; ++n) {
            if (1 - 1. / n <= l) {
                // std::cout << a << "^" << n << std::endl;
                ++count;
            } else {
                break;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}