#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <limits>
#include <algorithm>
#include <sstream>

typedef std::vector<int> Line;
typedef std::vector<Line> Table;

Table readTable()
{
    Table table;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int current;
        char tmp;
        Line v;
        while (ss >> current) {
            v.push_back(current);
            ss >> tmp;
        }
        table.push_back(std::move(v));
    }
    return table;
}

bool step(const Table& table, Table& mins)
{
    int size = table.size();
    bool changed = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            auto& minsIJ = mins[i][j];
            auto tableIJ = table[i][j];
            if (i > 0) {
                auto v = mins[i - 1][j] + tableIJ;
                if (v < minsIJ) {
                    minsIJ = v;
                    changed = true;
                }
            }
            if (i + 1 < size) {
                auto v = mins[i + 1][j] + tableIJ;
                if (v < minsIJ) {
                    minsIJ = v;
                    changed = true;
                }
            }
            if (j > 0) {
                auto v = mins[i][j - 1] + tableIJ;
                if (v < minsIJ) {
                    minsIJ = v;
                    changed = true;
                }
            }
            if (j + 1 < size) {
                auto v = mins[i][j + 1] + tableIJ;
                if (v < minsIJ) {
                    minsIJ = v;
                    changed = true;
                }
            }
        }
    }
    return changed;
}

int main()
{
    auto table = readTable();
    Table mins;
    int size = table.size();
    for (int i = 0; i < size; ++i) {
        mins.push_back(Line(size, std::numeric_limits<int>::max() / 10));
    }
    mins[0][0] = table[0][0];

    while(step(table, mins));

    // for (const auto& v: mins) {
    //     for (auto i: v) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << mins[size - 1][size - 1] << std::endl;


    return 0;
}