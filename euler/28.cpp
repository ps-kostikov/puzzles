#include <iostream>
#include <cmath>

struct Point
{
    int x;
    int y;
};

class ShiftGenerator
{
public:
    ShiftGenerator():
    limit_(1), sign_(1), xDone_(0), yDone_(0)
    {}

    Point next()
    {
        if (xDone_ < limit_) {
            ++xDone_;
            return Point{sign_, 0};
        }
        if (yDone_ < limit_) {
            ++yDone_;
            return Point{0, sign_};
        }
        sign_ = -1 * sign_;
        ++limit_;
        xDone_ = 1;
        yDone_ = 0;
        return Point{sign_, 0};
    }

private:
    int limit_;
    int sign_;
    int xDone_;
    int yDone_;
};


int main()
{
    int sum = 0;
    Point point{0, 0};
    ShiftGenerator shiftGen;
    int limit = 1001;
    for (int i = 1; i <= limit * limit; ++i) {
        if (std::abs(point.x) == std::abs(point.y)) {
            sum += i;
        }
        auto shift = shiftGen.next();
        point.x += shift.x;
        point.y += shift.y;
    }

    std::cout << "sum = " << sum << std::endl;
    return 0;
}