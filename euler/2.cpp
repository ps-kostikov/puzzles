#include <iostream>

int main()
{
    int prev = 1;
    int current = 2;
    int next = 0;
    int sum = 2;
    while (true) {
        next = prev + current;
        if (next > 4000000) {
            break;
        }
        if (!(next % 2)) {
           sum += next;
        }
        prev = current;
        current = next;
    }
    std::cout << sum << std::endl;
}