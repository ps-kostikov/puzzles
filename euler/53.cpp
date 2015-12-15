#include <iostream>

int eval(int n, int limit)
{
    int currentC = 1;
    for (int r = 1; r <= n / 2; ++r) {
        currentC = (currentC * (n - r + 1)) / r;
        if (currentC > limit) {
            return n + 1 - 2 * r;
        }
    }
    return 0;
}

int main()
{
    int sum = 0;
    for (int n = 1; n <= 100; ++n) {
        sum += eval(n, 1000000);
    }
    std::cout << sum << std::endl;
    return 0;
}