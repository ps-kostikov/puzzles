#include "common.h"

#include <iostream>
#include <algorithm>


int count(Natural prime, int numToReplace, const Naturals& primes)
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
            if (std::binary_search(primes.begin(), primes.end(), cand)) {
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
    PrimeGenerator gen;
    Naturals primes;

    // std::vector<int> v{0, 1, 1};
    // do {
    //     for (auto i: v) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // } while(std::next_permutation(v.begin(), v.end()));
    int maxToReplace = 1;
    for (Natural limit = 100; true; limit *= 10) {
        do {
            primes.push_back(gen.next());
        } while (gen.max() < limit);

        for (auto prime: primes) {
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

    // Natural max = 1000000;
    // while (gen.next() < max);
    // auto primes = gen.all();
    // primes.pop_back();

    // Natural bestLen = 0;
    // Natural bestPrime = 0;
    // for (size_t left = 0; left < primes.size(); ++left) {

    //     Natural sum = 0;
    //     for (size_t i = left; i < primes.size(); ++i) {
    //         sum += primes[i];
    //         if (sum > max) {
    //             break;
    //         }

    //         auto len = i - left + 1;
    //         if (len > bestLen) {
    //             if (std::binary_search(primes.begin(), primes.end(), sum)) {
    //                 bestLen = len;
    //                 bestPrime = sum;
    //             }
    //         }
    //     }
    // }
    // std::cout << bestPrime << std::endl;
    return 0;
}