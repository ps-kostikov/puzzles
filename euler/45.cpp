#include "common.h"

#include <iostream>

Natural t(Natural n)
{
    return (n * (n + 1)) / 2;
}

Natural p(Natural n)
{
    return (n * (3 * n - 1)) / 2;
}

Natural h(Natural n)
{
    return n * (2 * n - 1);
}

int main()
{
    Natural nt = 1;
    Natural np = 1;
    Natural nh = 1;
    while (true) {
        if (t(nt) < p(np)) {
            ++nt;
        } else if (t(nt) > p(np)) {
            ++np;
        } else if (t(nt) > h(nh)) {
            ++nh;
        } else if (t(nt) < h(nh)) {
            ++nt;
        } else {
            // std::cout << nt << ", " << np << ", " << nh << ": " << t(nt) << std::endl;
            if (t(nt) > 40755) {
                std::cout << t(nt) << std::endl;
                break;
            }
            ++nt;
        }
    }
    return 0;
}