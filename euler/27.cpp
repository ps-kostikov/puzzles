#include <iostream>
#include <vector>
#include <algorithm>

#include "common.h"

PrimeGenerator primeGenerator;

int evalNum(int a, int b)
{
    int result = 0;
    for (int n = 0; true; ++n) {
        int f = n * n + a * n + b;
        if (f <= 0) {
            return result;
        }
        if (primeGenerator.max() < f) {
            while (primeGenerator.next() < f) {
                ;
            }
        }
        auto primes = primeGenerator.all();
        auto it = std::find(primes.begin(), primes.end(), f);
        if (it == primes.end()) {
            return result;
        } else {
            ++result;
        }
    }
}

int main()
{
    int limit = 1000;
    int bestNum = 0;
    int bestProduct = 0;
    primeGenerator.next();
    for (int a = -limit + 1; a < limit; ++a) {
        for (int b = -limit + 1; b < limit; ++b) {
            int num = evalNum(a, b);
            if (num > bestNum) {
                bestNum = num;
                bestProduct = a * b;
            }
        }
    }
    // std::cout << "bestNum = " << bestNum << std::endl;
    // std::cout << "bestProduct = " << bestProduct << std::endl;
    std::cout << bestProduct << std::endl;
    return 0;
}