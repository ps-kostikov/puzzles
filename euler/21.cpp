#include <iostream>
#include <cmath>
#include <map>

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

int main()
{
    std::map<int, int> n_to_d;
    int maxN = 10000;
    for (int n = 1; n <= maxN; ++n) {
        n_to_d[n] = d(n);
    }
    int sum = 0;
    for (int n = 1; n <= maxN; ++n) {
        auto dn = n_to_d[n];
        if (dn == n) {
            continue;
        }
        if (dn > maxN) {
            continue;
        }
        if (n_to_d[dn] == n) {
            // std::cout << n << ": " << dn << std::endl;
            sum += n;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}