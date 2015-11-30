#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>

#include "common.h"


int main()
{
    const size_t N = 20;
    Natural table[N + 1][N + 1];
    for (size_t i = 0; i <= N; ++i) {
        table[i][0] = 1;
        table[0][i] = 1;
    }
    for (size_t i = 1; i <= N; ++i) {
        for (size_t j = 1; j <= N; ++j) {
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }
    std::cout << "hello" << std::endl;
    std::cout << "2,2: " << table[2][2] << std::endl;
    std::cout << "20,20: " << table[20][20] << std::endl;
    return 0;
}