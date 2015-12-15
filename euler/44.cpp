#include <iostream>
#include <vector>
#include <algorithm>

int pn(int n)
{
    return (n * (3 * n - 1)) / 2;
}

int main()
{
    std::vector<int> pns;
    for (int maxIndex = 0; true; ++maxIndex) {
        for (int i = pns.size(); i <= maxIndex; ++i) {
            pns.push_back(pn(1 + pns.size()));
        }
        for (int minIndex = 0; minIndex < maxIndex; ++minIndex) {
            int max = pns[maxIndex];
            int min = pns[minIndex];
            if (not std::binary_search(pns.begin(), pns.end(), max - min)) {
                continue;
            }
            int sum = max + min;
            while (sum > *pns.rbegin()) {
                pns.push_back(pn(1 + pns.size()));
            }
            if (std::binary_search(pns.begin(), pns.end(), sum)) {
                // std::cout << min << std::endl;
                // std::cout << max << std::endl;
                std::cout << max - min << std::endl;
                return 0;
            }
        }
    }
    return 0;
}