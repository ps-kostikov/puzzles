#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>

// v[0] - number of A1
// v[1] - number of A2
// v[2] - number of A3
// v[3] - number of A4
// v[4] - number of A5
typedef std::vector<int> Envelope;
const size_t N = 5;

std::ostream& operator<<(std::ostream& out, const Envelope& e)
{
    for (size_t index = 0; index < N; ++index) {
        out << "A" << index + 1 << ":" << e[index] << " ";
    }
    out << std::endl;
    return out;
}

Envelope makeChoice(const Envelope& e, size_t choice)
{
    Envelope result(e);
    --result[choice];
    for (size_t index = choice + 1; index < N; ++index) {
        ++result[index];
    }
    return result;
}

double evalAvg(const Envelope& e)
{
    double avg{0.};
    int totalSheet = 0;
    for (auto num: e) {
        totalSheet += num;
    }
    if (totalSheet == 0) {
        return 0.;
    }
    if (totalSheet == 1 and e[0] != 1 and e[N - 1] != 1) {
        avg += 1.;
    }
    for (size_t choice = 0; choice < N; ++choice) {
        if (e[choice] == 0) {
            continue;
        }
        auto prob = static_cast<double>(e[choice]) / totalSheet;
        avg += prob * evalAvg(makeChoice(e, choice));
    }
    return avg;
}

int main()
{
    Envelope init(N, 0);
    init[0] = 1;
    std::cout << init << std::endl;
    std::cout << makeChoice(init, 0) << std::endl;
    // std::cout << makeChoice(init, 1) << std::endl;
    // std::cout << makeChoice(init, 2) << std::endl;
    // std::cout << makeChoice(init, 3) << std::endl;
    std::cout.precision(6);
    std::cout << std::fixed << evalAvg(init) << std::endl;
    return 0;
}