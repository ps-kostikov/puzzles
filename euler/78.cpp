#include "common.h"

#include <iostream>
#include <algorithm>
#include <map>

std::map<std::pair<Natural, Natural>, Natural> cache;

// Natural f(Natural n, Natural maxPart)
// {
//     std::pair<Natural, Natural> key(n, maxPart);
//     if (cache.count(key) > 0) {
//         return cache[key];
//     }
//     if (n == 0) {
//         return 1;
//     }
//     if (maxPart == 1) {
//         return 1;
//     }
//     Natural total = 0;
//     for (Natural firstPart = 1; firstPart <= std::min(n, maxPart); ++firstPart) {
//         total += f(n - firstPart, firstPart);
//     }
//     total = total % 1000000;
//     cache[key] = total;
//     return total;
// }

Natural f(Natural n, Natural maxPart)
{
    // std::cout << n << " - " << maxPart << std::endl;
    if (n == 0 and maxPart == 0) {
        return 1;
    }
    if (maxPart == 0) {
        return 0;
    }
    if (maxPart > n) {
        return f(n, n);
    }
    std::pair<Natural, Natural> key(n, maxPart);
    if (cache.count(key) > 0) {
        return cache[key];
    }
    Natural total = f(n, maxPart - 1) + f(n - maxPart, maxPart);
    total = total % 1000000;
    cache[key] = total;
    return total;
}


Natural p(Natural n)
{
    return f(n, n);
}


int main()
{
    // for (Natural n = 1; true; ++n) {
    //     auto pn = p(n);
    //     // std::cout << n << ": " << p(n) << std::endl;
    //     if (pn % 1000000 == 0) {
    //         std::cout << n << ": " << pn << std::endl;
    //         break;
    //     }
    //     if (pn % 1000 == 0) {
    //         std::cout << n << ": " << pn << std::endl;
    //         break;
    //     }
    // }

    // for (Natural n = 1; n <= 10; ++n) {
    //     std::cout << n << ": " << p(n) << std::endl;
    // }

    std::vector<Natural> ps;
    std::vector<int> kSigns{1, -1};
    ps.push_back(1);
    ps.push_back(1);
    for (Natural n = 2; true; ++n) {
        long long result = 0;
        for (int k = 1; true; ++k) {
            bool out = false;
            for (int kSign: kSigns) {
                int indexShift = (k * kSign * (3 * k * kSign - 1)) / 2;
                if (n < indexShift) {
                    ps.push_back(result);
                    // std::cout << n << ": " << result << " (" << p(n) << ")" << std::endl;
                    if (result % 1000000 == 0) {
                        // std::cout << n << ": " << result << std::endl;
                        std::cout << n << std::endl;
                        return 0;
                    }
                    // if (result % 1000 == 0) {
                    //     std::cout << n << ": " << result << std::endl;
                    // }
                    out = true;
                    break;
                }

                int sign = 1;
                if ((k - 1) % 2 == 1) {
                    sign = -1;
                }
                result += (sign * ps[n - indexShift]);
                result = result % 1000000;

            }
            if (out) {
                break;
            }
        }
    }
    // std::cout << f(2, 2) << std::endl;
    return 0;
}