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

enum Result {
    Win,
    Lost,
    NotPlayed
};

void countWP(vector<vector<Result> >&in, vector<double>* wp) {
    *wp = vector<double> (in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        double res = 0;
        int pn = 0;
        for (size_t j = 0; j < in.size(); ++j) {
            if (in[i][j] == NotPlayed) {
                continue;
            }
            pn ++;
            if (in[i][j] == Win) {
                res += 1.;
            }
        }
        res /= pn;
        (*wp)[i] = res;
    }
}

void countOWP(vector<vector<Result> >&in, vector<double>* owp) {
    *owp = vector<double> (in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        double owp_ = 0;
        int pn = 0;
        for (size_t i1 = 0; i1 < in.size(); ++i1) {
            if (in[i][i1] == NotPlayed) {
                continue;
            }
            pn ++;
            
            double wp = 0;
            int opn = 0;
            for (size_t j1 = 0; j1 < in.size(); ++j1) {
                if (in[i1][j1] == NotPlayed || j1 == i) {
                    continue;
                }
                opn ++;
                if (in[i1][j1] == Win) {
                    wp += 1.;
                }
            }
            wp /= opn;
            owp_ += wp;
        }
        owp_ /= pn;
        (*owp)[i] = owp_;
    }
}

void countOOWP(vector<vector<Result> >& in, vector<double>& owp, vector<double>* oowp) {
    *oowp = vector<double> (in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        double res = 0;
        int pn = 0;
        for (size_t j = 0; j < in.size(); ++j) {
            if (in[i][j] == NotPlayed) {
                continue;
            }
            pn ++;
            res += owp[j];
        }
        res /= pn;
        (*oowp)[i] = res;
    }
}

void solve(vector<vector<Result> >& in, vector<double> *out) {
    vector<double> wp, owp, oowp;
    countWP(in, &wp);
    countOWP(in, &owp);
    countOOWP(in, owp, &oowp);

    *out = vector<double> (in.size(), 0.);
    for (size_t i = 0; i < in.size(); ++i) {
        (*out)[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
    }
}

void input(vector<vector<Result> >* in) {
    size_t size;
    cin >> size;
    *in = vector<vector<Result> > (size);
    char c; 
    for( size_t i = 0; i < size; ++i) {
        (*in)[i] = vector<Result>(size);
        for( size_t j = 0; j < size; ++j) {
            cin >> c;
            if (c == '1') {
                (*in)[i][j] = Win;
            } else if (c == '0') {
                (*in)[i][j] = Lost;
            } else if (c == '.') {
                (*in)[i][j] = NotPlayed;
            }
        }
    }

}

void output(const vector<double>& out) {
    static int testCase = 1;
    cout << "Case #" << testCase << ": " << endl;
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i] << endl;
    }
    testCase++;
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<Result> > in;
    for (int i = 0; i < N; ++i) {
        input(&in);
        vector<double> out;
        solve(in, &out);
        output(out);
    }
    return 0;
}
