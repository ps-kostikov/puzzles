#include <iostream>
#include <vector>


int periodSize(int d)
{
    std::vector<int> rests;
    int currentRest = 1;
    while (true) {
        int nextRest = (currentRest * 10) % d;
        if (nextRest == 0) {
            return 0;
        }
        for (size_t i = 0; i < rests.size(); ++i) {
            if (nextRest == rests[i]) {
                return rests.size() - i;
            }
        }
        rests.push_back(nextRest);
        currentRest = nextRest;
    }
}

int main()
{
    int longestPeriod = 0;
    int bestD = 0;
    for (int d = 1; d < 1000; ++d) {
        auto ps = periodSize(d);
        if (ps > longestPeriod) {
            longestPeriod = ps;
            bestD = d;
        }
    }
    std::cout << bestD << std::endl;
    return 0;
}