#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int d(int n)
{
    auto limit = n / 2;
    int sum = 0;
    for (int cand = 1; cand <= limit; ++cand) {
        if (n % cand == 0) {
            sum += cand;
        }
    }
    return sum;
}

bool canBeSum(std::vector<int> sortedList, int n)
{
    for (auto onePart: sortedList) {
        if (std::binary_search(sortedList.begin(), sortedList.end(), n - onePart)) {
            return true;
        }
    }
    return false;
}

int main()
{
    int maxN = 28123;
    std::vector<int> abundant;
    for (int n = 1; n <= maxN; ++n) {
        if (d(n) > n) {
            abundant.push_back(n);
        }
    }
    std::cout << abundant.size() << std::endl;
    std::sort(abundant.begin(), abundant.end());

    for (int x: {1, 12, 24, maxN}) {
        std::cout << x << ": " << canBeSum(abundant, x) << std::endl;
    }

    int sum = 0;
    for (int n = 1; n <= maxN; ++n) {
        if (not canBeSum(abundant, n)) {
            sum += n;
        }
    }
    std::cout << "sum = " << sum << std::endl;
    return 0;
}