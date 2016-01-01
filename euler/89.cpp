#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <stdexcept>
#include <sstream>


int bestNumOfDigits(int n)
{
    if (n >= 10000) {
        throw std::runtime_error("too big number");
    }
    int sum = n / 1000;
    auto digitToNum = [](int d) {
        if (d <= 3) {
            return d;
        }
        if (d == 5) {
            return 1;
        }
        if (d == 7) {
            return 3;
        }
        if (d == 8) {
            return 4;
        }
        return 2;
    };
// 0 0
// 1 1
// 2 2
// 3 3
// 4 2
// 5 1
// 6 2
// 7 3
// 8 3
// 9 2
    n = n % 1000;
    while (n > 0) {
        sum += digitToNum(n % 10);
        n /= 10;
    }
    return sum;
}

int fromString(const std::string& s)
{
    int sum = 0;
    int subsum = 0;
    int last = 10000;
    int cur = 0;
    for (auto c: s) {
        if (c == 'M') {
            cur = 1000;
        } else if (c == 'D') {
            cur = 500;
        } else if (c == 'C') {
            cur = 100;
        } else if (c == 'L') {
            cur = 50;
        } else if (c == 'X') {
            cur = 10;
        } else if (c == 'V') {
            cur = 5;
        } else if (c == 'I') {
            cur = 1;
        } else {
            throw std::runtime_error("unexpected letter");
        }
        if (cur < last) {
            sum += subsum;
            subsum = cur;
            last = cur;
        } else if (cur > last) {
            sum += (cur - subsum);
            subsum = 0;
            last = cur;
        } else {
            subsum += cur;
        }
    }
    return sum + subsum;
}

int main()
{
    // for (int n: {16, 1606}) {
    //     std::cout << n << ": " << bestNumOfDigits(n) << std::endl;
    // }

    int result = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        // std::cout << fromString(line) << std::endl;
        // std::cout << line << std::endl;
        result += (line.size() - bestNumOfDigits(fromString(line)));
    }
    std::cout << result << std::endl;
    return 0;
}