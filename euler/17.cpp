#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

#include "common.h"

std::vector<std::vector<int>> readTable()
{
    std::vector<std::vector<int>> table;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int current;
        std::vector<int> v;
        while (ss >> current) {
            v.push_back(current);
        }
        table.push_back(std::move(v));
    }
    return table;
}

int sum(const std::vector<std::vector<int>>& table, unsigned path)
{
    int result = 0;
    size_t index = 0;
    for (size_t line = 0; line < table.size(); ++line) {
        result += table[line][index];
        index += (path & (1 << line)) ? 1 : 0;
    }
    return result;
}

int main()
{
    auto table = readTable();
    for (const auto& v: table) {
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    std::vector<int> sums;
    for (unsigned i = 0; i < (1 << (table.size() - 1)); ++i) {
        sums.push_back(sum(table, i));
    }
    std::cout << *std::max_element(sums.begin(), sums.end()) << std::endl;
    // std::cout << sum(table, 0) << std::endl;
    // std::cout << (1 << 4) << std::endl;
    // std::cout << (5 & (1 << 0)) << std::endl;
    // std::cout << (5 & (1 << 1)) << std::endl;
    // std::cout << (5 & (1 << 2)) << std::endl;
    // int size = 1;
    return 0;
}