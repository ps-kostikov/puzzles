#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <limits>
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

    for (int i = 0; i < size; ++i) {
        mins[i][0] = table[i][0];
    }

    for (int j = 1; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            int bestSum = std::numeric_limits<int>::max();
            for (int prevI = 0; prevI < size; ++prevI) {
                int sum = mins[prevI][j - 1];
                for (int nextI = std::min(i, prevI); nextI <= std::max(i, prevI); ++nextI) {
                    sum += table[nextI][j];
                }
                if (sum < bestSum) {
                    bestSum = sum;
                }
            }
            mins[i][j] = bestSum;
        }
    }

    // for (const auto& v: mins) {
    //     for (auto i: v) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // }

    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < size; ++i) {
        min = std::min(min, mins[i][size - 1]);
    }
    std::cout << min << std::endl;
    return 0;
}