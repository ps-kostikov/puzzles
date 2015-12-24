#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

std::vector<std::vector<int>> readTable()
{
    std::vector<std::vector<int>> table;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int current;
        char tmp;
        std::vector<int> v;
        while (ss >> current) {
            v.push_back(current);
            ss >> tmp;
        }
        table.push_back(std::move(v));
    }
    return table;
}


int main()
{
    auto table = readTable();
    std::vector<std::vector<int>> mins;
    int size = table.size();
    for (int i = 0; i < size; ++i) {
        mins.push_back(std::vector<int>(size, 0));
    }
    // for (const auto& v: mins) {
    //     for (auto i: v) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 and j == 0) {
                mins[i][j] = table[i][j];
            } else if (i == 0) {
                mins[i][j] = mins[i][j - 1] + table[i][j];
            } else if (j == 0) {
                mins[i][j] = mins[i - 1][j] + table[i][j];
            } else {
                mins[i][j] = std::min(mins[i][j - 1], mins[i - 1][j]) + table[i][j];
            }
        }
    }
    std::cout << mins[size - 1][size - 1] << std::endl;
    return 0;
}