#include "common.h"

#include <iostream>

int main()
{
    Natural n = 600851475143;
    auto reduce = primeReduce(n);
    std::cout << reduce.back() << std::endl;
}