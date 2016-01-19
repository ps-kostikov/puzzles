#include <iostream>
#include <algorithm>
#include <vector>

bool check(int aSquare, int bSquare, int cSquare)
{
    std::vector<int> v{aSquare, bSquare, cSquare};
    std::sort(v.begin(), v.end());
    return v[0] + v[1] == v[2];
}

int main()
{
    int limit = 50;
    int cnt = 0;
    for (int x1 = 0; x1 <= limit; ++x1) {
        for (int y1 = 0; y1 <= limit; ++y1) {
            if (x1 == 0 and y1 == 0) {
                continue;
            }
            for (int x2 = 0; x2 <= limit; ++x2) {
                for (int y2 = 0; y2 <= limit; ++y2) {
                    if (x2 == 0 and y2 == 0) {
                        continue;
                    }
                    if (x1 == x2 and y1 == y2) {
                        continue;
                    }
                    auto r = check(
                        x1 * x1 + y1 * y1,
                        x2 * x2 + y2 * y2,
                        (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
                    );
                    if (r) {
                        ++cnt;
                    }
                }
            }
        }
    }
    std::cout << cnt / 2 << std::endl;
    return 0;
}