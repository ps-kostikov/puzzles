#include "common.h"

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int maxPerim = 1500000;
    std::vector<int> counts(maxPerim + 1, 0);
    for (int n = 1; n * n <= maxPerim; ++n) {
        for (int m = n + 1; n * n + m * m <= maxPerim; ++m) {
            for (int k = 1; k * (n * n + m * m) <= maxPerim; ++k ) {
                if (GCD(m, n) != 1) {
                    continue;
                }
                if ((m - n) % 2 == 0) {
                    continue;
                }
                int a = k * (m * m - n * n);
                int b = 2 * k * m * n;
                int c = k * (m * m + n * n);

                int perim = a + b + c;
                if (perim <= maxPerim) {
                    ++counts[static_cast<size_t>(perim)];
                }
            }
        }
    }
    int count = 0;
    for (auto c: counts) {
        if (c == 1) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}