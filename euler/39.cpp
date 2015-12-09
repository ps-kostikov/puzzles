#include <iostream>
#include <vector>
#include <algorithm>

int nod(int a, int b) {
    if (a <= 0 or b <= 0) {
        return 0;
    }

    int max = std::max(a, b);
    int min = std::min(a, b);
    if (max % min == 0) {
        return min;
    }
    return nod(min, max - min * (max / min));
}

int main()
{
    int maxPerim = 1000;
    std::vector<int> counts(maxPerim + 1, 0);
    for (int n = 1; n * n <= maxPerim; ++n) {
        for (int m = n + 1; n * n + m * m <= maxPerim; ++m) {
            for (int k = 1; k * (n * n + m * m) <= maxPerim; ++k ) {
                if (nod(m, n) != 1) {
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
    auto maxElIt = std::max_element(counts.begin(), counts.end());
    std::cout << "max perim = " << maxElIt - counts.begin()
        << " count = " << *maxElIt << std::endl;
    return 0;
}