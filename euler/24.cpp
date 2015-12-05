#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& digits)
{
    for (auto d: digits) {
        out << d;
    }
    return out;   
}

int main()
{
    std::vector<int> digits;
    for (int n = 0; n < 10; ++n) {
        digits.push_back(n);
    }
    int targetIndex = 1000000;
    int index = 1;
    do {
        if (index >= targetIndex - 1) {
            std::cout << index << ": " << digits << std::endl;
        }
        if (index >= targetIndex + 1) {
            break;
        }
        ++index;
    } while (std::next_permutation(digits.begin(), digits.end()));
    return 0;
}