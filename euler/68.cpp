#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>


bool check(const std::vector<int>& v)
{
    int sum = v[5] + v[0] + v[1];
    if (v[6] + v[1] + v[2] != sum) {
        return false;
    }
    if (v[7] + v[2] + v[3] != sum) {
        return false;
    }
    if (v[8] + v[3] + v[4] != sum) {
        return false;
    }
    if (v[9] + v[4] + v[0] != sum) {
        return false;
    }
    return true;
}

std::string toStrPart(const std::vector<int>& v, size_t index)
{
    if (index == 5) {
        return std::to_string(v[5]) + std::to_string(v[0]) + std::to_string(v[1]);
    } else if (index == 6) {
        return std::to_string(v[6]) + std::to_string(v[1]) + std::to_string(v[2]);
    } else if (index == 7) {
        return std::to_string(v[7]) + std::to_string(v[2]) + std::to_string(v[3]);
    } else if (index == 8) {
        return std::to_string(v[8]) + std::to_string(v[3]) + std::to_string(v[4]);
    } else if (index == 9) {
        return std::to_string(v[9]) + std::to_string(v[4]) + std::to_string(v[0]);
    }
    throw std::runtime_error("bad index");
}

std::string toStr(const std::vector<int>& v)
{
    int min = std::min({v[5], v[6], v[7], v[8], v[9]});
    const size_t globalShift = 5;
    size_t minIndex = 0;
    for (size_t index = 0; index < 5; ++index) {
        if (min == v[index + globalShift]) {
            minIndex = index;
        }
    }
    std::string result;
    for (size_t shift = 0; shift < 5; ++shift) {
        result += toStrPart(v, (minIndex + shift) % globalShift + globalShift);
    }
    return result;
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int cnt = 0;
    std::vector<std::string> best;
    do {
        if (check(v)) {
            // std::cout << toStr(v) << std::endl;
            best.push_back(toStr(v));
            ++cnt;
        }
    } while (std::next_permutation(v.begin(), v.end() - 1));
    // std::cout << cnt << std::endl;
    std::cout << *std::max_element(best.begin(), best.end()) << std::endl;
    return 0;
}