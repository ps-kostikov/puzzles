#include <iostream>
#include <vector>


bool check(int n, const std::vector<int>& facts) {
    int tmp = n;
    int sum = 0;
    while (tmp != 0) {
        sum += facts[static_cast<size_t>(tmp % 10)];
        tmp /= 10;
    }
    return sum == n;
}

int main()
{
    std::vector<int> facts(10);
    facts[0] = 1;
    facts[1] = 1;
    for (size_t index = 2; index <= 9; ++index) {
        facts[index] = index * facts[index - 1];
    }
    int sum = 0;
    for (int i = 10; i < 9000000; ++i) {
        if (check(i, facts)) {
            // std::cout << i << std::endl;
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
