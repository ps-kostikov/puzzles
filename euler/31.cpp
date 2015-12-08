
#include <iostream>
#include <set>

int eval(const std::set<int>& coins, int amount)
{
    if (coins.size() == 1) {
        if (amount % *coins.begin() == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    int sum = 0;
    auto coin = *coins.rbegin();
    std::set<int> restCoins(coins.begin(), coins.end());
    restCoins.erase(coin);
    for (int number = 0; number * coin <= amount; ++number) {
        sum += eval(restCoins, amount - number * coin);
    }
    return sum;
}


int main()
{
    std::set<int> coins{1, 2, 5, 10, 20, 50, 100, 200};
    std::cout << eval(coins, 200) << std::endl;
}