#include "common.h"

#include <iostream>
#include <vector>
#include <algorithm>

struct Fraction
{
    int numerator;
    int denominator;
};

bool operator<(const Fraction& left, const Fraction& right)
{
    return left.numerator * right.denominator < right.numerator * left.denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

int evalNum(int den, int boundNum, int boundDen)
{
    auto approx = static_cast<int>((den * boundNum) / static_cast<double>(boundDen));
    if (approx == 0) {
        return 0;
    }
    while (GCD(approx, den) != 1) {
        --approx;
    }
    return approx;
}

int main()
{
    std::vector<Fraction> fractions;
    int boundNum = 3;
    int boundDen = 7;
    for (int den = 2; den <= 1000000; ++den) {
        if (den == boundDen) {
            continue;
        }
        auto num = evalNum(den, boundNum, boundDen);
        // std::cout << num << "/" << den << std::endl;
        fractions.push_back(Fraction{num, den});
    }
    std::cout << std::max_element(fractions.begin(), fractions.end())->numerator << std::endl;
    return 0;
}