#include "common.h"

#include <iostream>
#include <set>

int main()
{
    int limit = 50000000;
    common::Primes primes;
    std::set<int> counted;
    for (int i1 = 0; true; ++i1) {
        auto s1 = primes[i1] * primes[i1];
        if (s1 >= limit) {
            break;
        }
        for (int i2 = 0; true; ++i2) {
            auto s2 = primes[i2] * primes[i2] * primes[i2];
            if (s1 + s2 >= limit) {
                break;
            }
            for (int i3 = 0; true; ++i3) {
                auto s3 = primes[i3] * primes[i3] * primes[i3] * primes[i3];
                auto s = s1 + s2 + s3;
                if (s >= limit) {
                    break;
                }
                if (counted.count(s) == 0) {
                    counted.insert(s);
                }
            }
        }
    }
    std::cout << counted.size() << std::endl;
    return 0;
}