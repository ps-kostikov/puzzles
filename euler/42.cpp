#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

int charValue(char c)
{
    return (c - 'A') + 1;
}

int wordValue(const std::string& word)
{
    int sum = 0;
    for (auto c: word) {
        sum += charValue(c);
    }
    return sum;
}

std::vector<std::string> read()
{
    std::vector<std::string> result;
    std::string tmp;
    char current;
    while(std::cin.get(current)) {
        if (current == '"' or current == ',' or current == ' ') {
            if (tmp.empty()) {
                continue;
            }
            result.push_back(tmp);
            tmp = "";
        } else {
            tmp += current;
        }
    }
    return result;
}

int main()
{
    auto strs = read();
    std::vector<int> values;
    for (auto& s: strs) {
        values.push_back(wordValue(s));
    }
    int max = *std::max_element(values.begin(), values.end());
    std::set<int> numbers;
    for (int n = 1; true; ++n) {
        auto number = (n * (n + 1)) / 2;
        numbers.insert(number);
        if (number > max) {
            break;
        }
    }
    int total = 0;
    for (auto v: values) {
        if (numbers.count(v) > 0) {
            ++total;
        }
    }
    std::cout << total << std::endl;
    return 0;
}