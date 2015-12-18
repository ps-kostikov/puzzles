#include "common.h"

#include <iostream>
#include <algorithm>


int count(Natural prime, int numToReplace, common::Primes& primes)
{
    auto digits = common::toDigits(prime, 10);
    int best = 0;
    std::vector<int> mask;
    for (int i = 0; i < digits.size() - numToReplace; ++i) {
        mask.push_back(0);
    }
    for (int i = 0; i < numToReplace; ++i) {
        mask.push_back(1);
    }
    do {
        int count = 0;
        int firstDigitToReplace = 0;
        if (mask[0] == 1) {
            firstDigitToReplace = 1;
        }
        bool isPartOf = false;
        for (int digitToReplace = firstDigitToReplace; digitToReplace <= 9; ++digitToReplace) {
            auto fixedDigits = digits;
            for (int i = 0; i < mask.size(); ++i) {
                if (mask[i] == 1) {
                    fixedDigits[i] = digitToReplace;
                }
            }
            Natural cand = common::fromDigits(fixedDigits, 10);
            if (primes.contain(cand)) {
                if (cand == prime) {
                    isPartOf = true;
                }
                // std::cout << "    " << cand << std::endl;
                ++count;
            }
        }
        // std::cout << "====" << std::endl;
        if (isPartOf) {
            best = std::max(best, count);
        }
    } while (std::next_permutation(mask.begin(), mask.end()));
    return best;
}

int main()
{
    common::Primes primes;

    int maxToReplace = 1;
    for (Natural limit = 100; true; limit *= 10) {

        for (Natural index = 0; true; ++index) {
            auto prime = primes[index];
            if (prime < limit / 10) {
                continue;
            }
            if (prime > limit) {
                break;
            }
            for (int toReplace = 1; toReplace <= maxToReplace; ++toReplace) {
                int cnt = count(prime, toReplace, primes);
                // std::cout << prime << " " << cnt << std::endl;
                if (cnt == 8) {
                    std::cout << prime << std::endl;
                    // std::cout << toReplace << std::endl;
                    return 0;
                }
            }
        }
        ++maxToReplace;
    }

    return 0;
}