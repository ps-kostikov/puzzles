#include "common.h"

#include <iostream>


bool eq(int num1, int denom1, int num2, int denom2) {
    return num1 * denom2 == num2 * denom1;
}


int main()
{
    int finalNum = 1;
    int finalDenom = 1;
    for (int numerator = 10; numerator < 99; ++numerator) {
        for (int denominator = numerator + 1; denominator <= 99; ++denominator) {
            int numOnes = numerator % 10;
            int numTens = numerator / 10;
            int denomOnes = denominator % 10;
            int denomTens = denominator / 10;
            if (numOnes == denomTens) {
                if (eq(numerator, denominator, numTens, denomOnes)) {
                    // std::cout << numerator << "/" << denominator << std::endl;
                    finalNum *= numerator;
                    finalDenom *= denominator;
                }
            }
        }
    }
    // std::cout << finalNum << "/" << finalDenom << std::endl;
    auto gcd = GCD(finalNum, finalDenom);
    // std::cout << finalNum / gcd << "/" << finalDenom / gcd << std::endl;
    std::cout << finalDenom / gcd << std::endl;
    return 0;
}
