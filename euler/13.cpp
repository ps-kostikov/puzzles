#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>

class LongInt
{
public:
    typedef std::vector<size_t> Digits;

    LongInt() {}

    LongInt(Digits digits):
        digits_(std::move(digits))
    {}

    LongInt operator+(const LongInt& other)
    {
        Digits result;
        size_t fromPrev = 0;
        size_t minSize = std::min(digits_.size(), other.digits_.size());
        for (size_t i = 0; i < minSize; ++i) {
            auto sum = fromPrev + digits_[i] + other.digits_[i];
            result.push_back(sum % base_);
            fromPrev = sum / base_;
        }

        Digits& rest = digits_;
        if (rest.size() == minSize) {
            rest = other.digits_;
        }
        for (size_t i = minSize; i < rest.size(); ++i) {
            auto sum = fromPrev + rest[i];
            result.push_back(sum % base_);
            fromPrev = sum / base_;
        }
        if (fromPrev > 0) {
            result.push_back(fromPrev);
        }
        return LongInt(result);
    }

    LongInt firstDigits(size_t num)
    {
        if (num >= digits_.size()) {
            return *this;
        }
        return LongInt(Digits(digits_.end() - num, digits_.end()));
    }

private:
    friend std::istream& operator>>(std::istream&, LongInt&);
    friend std::ostream& operator<<(std::ostream&, const LongInt&);

    static const size_t base_ = 10;
    Digits digits_;
};


std::istream& operator>>(std::istream& is, LongInt& i)
{
    std::string s;
    is >> s;
    if (!is) {
        return is;
    }
    LongInt::Digits digits;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        digits.push_back(*it - '0');
    }
    i.digits_ = digits;
    return is;
}


std::ostream& operator<<(std::ostream& os, const LongInt& i)
{
    for (auto it = i.digits_.rbegin(); it != i.digits_.rend(); ++it) {
        os << *it;
    }
    return os;
}


int main()
{
    std::cout << "hello" << std::endl;
    LongInt next;
    LongInt sum;
    while (std::cin >> next) {
        sum = sum + next;
        // cout << next;
        std::cout << next << std::endl;
    }
    std::cout << sum << std::endl;
    std::cout << sum.firstDigits(10) << std::endl;

    return 0;
}