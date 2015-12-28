#include "common.h"

#include <iostream>
#include <map>

std::map<int, int> cache{{1, 1}, {89, 89}};

int next(int n)
{
    auto digits = common::toDigits(n, 10);
    int sum = 0;
    for (auto digit: digits) {
        sum += digit * digit;
    }
    return sum;
}

int f(int n)
{
    while (true) {
        auto nn = next(n);
        auto it = cache.find(nn);
        if (it != cache.end()) {
            cache[n] = it->second;
            return it->second;
        }
        n = nn;
    }
}

bool check(int n)
{
    return f(n) == 89;
}

int main()
{
    int count = 0;
    for (int n = 1; n < 10000000; ++n) {
        if (check(n)) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}