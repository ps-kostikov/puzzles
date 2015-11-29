#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

using std::vector;
using std::string;

struct Pos {
    long long p;
    int v;
};

double solve(double D, vector<Pos>& poss, size_t begin, size_t end) {
    long long sumV = 0, minP = poss[begin].p, maxP = poss[begin].p;
    for (size_t i = begin; i <= end; ++i) {
        sumV += poss[i].v;
        minP = std::min(minP, poss[i].p);
        maxP = std::max(maxP, poss[i].p);
    }
    double res = (sumV - 1) * D - (maxP - minP);
    res /= 2.;
    return (res > 0.) ? res : 0.;
}

double solve(double D, vector<Pos>& poss) {
    double res = 0;
    for (size_t i = 0; i < poss.size(); ++i) {
        for (size_t j = 0; j < poss.size(); ++j) {
            res = std::max(res, solve(D, poss, i, j));
        }
    }
    return res;
}

void input(double &D, vector<Pos>* in) {
    size_t C;
    cin >> C >> D;
    *in = vector<Pos> (C);
    for( size_t i = 0; i < in->size(); ++i) {
        cin >> (*in)[i].p;
        cin >> (*in)[i].v;
    }

}

void output(double res) {
    static int testCase = 1;
    cout << "Case #" << testCase << ": " << std::fixed << res << endl;
    testCase++;
}

int main() {
    int N;
    cin >> N;
    
    vector<Pos> in;
    double D;
    for (int i = 0; i < N; ++i) {
        input(D, &in);
        double res = solve(D, in);
        output(res);
    }
    return 0;
}
