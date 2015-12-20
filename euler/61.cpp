#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


int triangle(int n)
{
    return (n * (n + 1)) / 2;
}

int square(int n)
{
    return n * n;
}

int pentagonal(int n)
{
    return (n * (3 * n - 1)) / 2;
}

int hexagonal(int n)
{
    return n * (2 * n - 1);
}

int heptagonal(int n)
{
    return (n * (5 * n - 3)) / 2;
}

int octagonal(int n)
{
    return n * (3 * n - 2);
}


std::vector<int> all(int f(int))
{
    std::vector<int> r;
    for (int n = 1; true; ++n) {
        int fn = f(n);
        if (fn >= 1000 and fn <= 9999) {
            r.push_back(fn);
        }
        if (fn > 9999) {
            break;
        }
    }
    return r;
}

bool checkSequence(const std::vector<int> v)
{
    for (size_t i = 0; i + 1 < v.size(); ++i) {
        if (v[i] % 100 != v[i + 1] / 100) {
            return false;
        }
    }
    if (*v.rbegin() % 100 != *v.begin() / 100) {
        return false;
    }
    return true;
}

bool check(const std::vector<int> v)
{
    std::vector<int> sorted(v.begin(), v.end());
    std::sort(sorted.begin(), sorted.end());
    do {
        if (checkSequence(sorted)) {
            return true;
        }
    } while (std::next_permutation(sorted.begin(), sorted.end()));
    return false;
}

int main()
{
    auto v3 = all(triangle);
    auto v4 = all(square);
    auto v5 = all(pentagonal);
    auto v6 = all(hexagonal);
    auto v7 = all(heptagonal);
    auto v8 = all(octagonal);

    for (auto i8: v8) {
        if (i8 % 100 < 10) {
            continue;
        }
        for (auto i7: v7) {
            if (i7 % 100 < 10) {
                continue;
            }
            for (auto i6: v6) {
                if (i6 % 100 < 10) {
                    continue;
                }
                for (auto i5: v5) {
                    if (i5 % 100 < 10) {
                        continue;
                    }
                    std::set<int> s{
                        i8 / 100, i7 / 100, i6 / 100, i5 / 100,
                        i8 % 100, i7 % 100, i6 % 100, i5 % 100
                    };

                    if (s.size() > 6) {
                       continue;
                    }
                    for (auto i4: v4) {
                        if (i4 % 100 < 10) {
                            continue;
                        }
                        std::set<int> ss{
                            i8 / 100, i7 / 100, i6 / 100, i5 / 100, i4 / 100,
                            i8 % 100, i7 % 100, i6 % 100, i5 % 100, i4 % 100
                        };

                        if (ss.size() > 6) {
                           continue;
                        }

                        for (auto i3: v3) {
                            if (i3 % 100 < 10) {
                                continue;
                            }
                            std::set<int> first{
                                i8 / 100, i7 / 100, i6 / 100, i5 / 100, i4 / 100, i3 / 100
                            };
                            std::set<int> last{
                                i8 % 100, i7 % 100, i6 % 100, i5 % 100, i4 % 100, i3 % 100
                            };

                            if (first != last) {
                                continue;
                            }
                            if (check(std::vector<int>{i8, i7, i6, i5, i4, i3})) {
                                int sum = i8 + i7 + i6 + i5 + i4 + i3;
                                std::cout << sum << std::endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}