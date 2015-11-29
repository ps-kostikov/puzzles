#include "common.h"

#include <iostream>

int main()
{
    std::cout << "hello" << std::endl;
    for (Natural n = 1; ;++n) {
        auto triangleNum = (n * (n + 1)) / 2;
        auto primeExps = primeReduceExp(triangleNum);
        Natural deviderCount = 1;
        for (auto primeExp: primeExps) {
            deviderCount *= (primeExp.exp + 1);
        }

        // std::cout << n << " " << triangleNum << " " << deviderCount << std::endl;
        if (deviderCount > 500) {
            std::cout << triangleNum << std::endl;
            break;
        }
    }
    return 0;
}