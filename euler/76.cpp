#include "common.h"

#include <iostream>
#include <algorithm>
#include <map>

std::map<std::pair<Natural, Natural>, Natural> cache;

Natural f(Natural n, Natural maxPart)
{
    std::pair<Natural, Natural> key(n, maxPart);
    if (cache.count(key) > 0) {
        return cache[key];
    }
    if (n == 0) {
        return 1;
    }
    if (maxPart == 1) {
        return 1;
    }
    Natural total = 0;
    for (Natural firstPart = 1; firstPart <= std::min(n, maxPart); ++firstPart) {
        total += f(n - firstPart, firstPart);
    }
    cache[key] = total;
    return total;
}

Natural p(Natural n)
{
    return f(n, n) - 1;
}

int main()
{
    std::cout << p(100) << std::endl;
    return 0;
}