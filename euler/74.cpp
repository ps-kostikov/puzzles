#include <iostream>
#include <vector>

std::vector<int> factorials;

int next(int n)
{
    int sum = 0;
    while (n != 0) {
        sum += factorials[n % 10];
        n /= 10;
    }
    return sum;
}

int length(int n)
{
    std::vector<int> v{n};
    while (true) {
        n = next(n);
        bool uniq = true;
        for (auto i: v) {
            if (i == n) {
                uniq = false;
                break;
            }
        }
        if (uniq) {
            v.push_back(n);
        } else {
            break;
        }
    }
    return v.size();
}

int main()
{
    factorials.push_back(1);
    for (int i = 1; i <= 9; ++i) {
        factorials.push_back(factorials[i - 1] * i);
    }

    int count = 0;
    for (int n = 1; n < 1000000; ++n) {
        if (length(n) == 60) {
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}