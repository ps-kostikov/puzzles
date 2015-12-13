#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>

#include "common.h"

struct Evaluator
{
    Evaluator()
    {
        cache[1] = 1;
    }

    Natural eval(Natural n)
    {
        if (auto it = cache.find(n) != cache.end()) {
            return cache[n];
        }
        Natural prevResult;
        if (n % 2 == 0) {
            prevResult = eval(n / 2);
        } else {
            prevResult = eval(3 * n + 1);
        }
        auto result = prevResult + 1;
        cache[n] = result;
        return result;
    }

    std::map<Natural, Natural> cache;
};

int main()
{
    auto evaluator = Evaluator();
    Naturals all;
    for (Natural i = 1; i <= 1000000; ++i) {
        all.push_back(i);
    }
    auto cmp = [&](Natural n1, Natural n2) {
        return evaluator.eval(n1) < evaluator.eval(n2);
    };
    auto best = *std::max_element(all.begin(), all.end(), cmp);
    // std::cout << best << ": " << evaluator.eval(best) << std::endl;
    // std::cout << "total evaluated: " << evaluator.cache.size() << std::endl;
    std::cout << best << std::endl;
    return 0;
}