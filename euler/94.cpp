#include <iostream>
#include <cmath>


int main()
{
    long long sum = 0;
    long long limit = 1000000000;
    for (long long n = 1; n * n <= limit; ++n) {
        for (long long m = n + 1; m * m <= limit; ++m) {
            long long A = m * m + n * n;
            long long B1 = 4 * m * n;
            if (std::abs(A - B1) == 1) {
                long long perim = 2 * A + B1;
                if (perim <= limit) {
                    // std::cout << "A = " << A << " B1 = " << B1 << std::endl;
                    sum += perim;
                }
            }
            long long B2 = 2 * (m * m - n * n);
            if (std::abs(A - B2) == 1) {
                long long perim = 2 * A + B2;
                if (perim <= limit) {
                    // std::cout << "A = " << A << " B2 = " << B2 << std::endl;
                    sum += perim;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}