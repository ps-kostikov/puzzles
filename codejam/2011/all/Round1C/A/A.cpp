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

bool replace(vector<vector<char> > &v, size_t sinceI, size_t sinceJ) {
    size_t I = v.size();
    size_t J = v[0].size();

    if (sinceI + 1 >= I || sinceJ + 1 >= J) {
        return false;
    }
    if (v[sinceI][sinceJ] != '#' ||
        v[sinceI][sinceJ+1] != '#' ||
        v[sinceI+1][sinceJ] != '#' ||
        v[sinceI+1][sinceJ+1] != '#') {
        return false;
    }
    v[sinceI][sinceJ] = '/';
    v[sinceI][sinceJ+1] = '\\';
    v[sinceI+1][sinceJ] = '\\';
    v[sinceI+1][sinceJ+1] = '/';
    return true;
}

bool findBlue(vector<vector<char> > &v, size_t sinceI, size_t sinceJ, bool& found) {
    size_t I = v.size();
    size_t J = v[0].size();

    for (size_t i = sinceI; i < I; ++i) {
        for (size_t j = sinceJ; j < J; ++j) {
            if (v[i][j] == '#') {
                found = true;
                return replace(v, i, j);
            }
        }
    }
    found = false;
}

bool solve(vector<vector<char> >& in, vector<vector<char> >* out) {
    *out = in;
    bool found = true;
    size_t i = 0, j = 0;
    while (found) {
        bool res = findBlue(*out, i, j, found);
        if (!res) {
            return false;
        }
    }
    return true;
}

void input(vector<vector<char> >* in) {
    size_t I, J;
    cin >> I >> J;
    *in = vector<vector<char> > (I);
    for( size_t i = 0; i < I; ++i) {
        (*in)[i] = vector<char>(J);
        for( size_t j = 0; j < J; ++j) {
            cin >> (*in)[i][j];
        }
    }

}

void output(bool cor, const vector<vector<char> >& out) {
    static int testCase = 1;
    cout << "Case #" << testCase << ": " << endl;
    if (!cor) {
        cout << "Impossible" << endl;
        testCase++;
        return;
    }
    size_t I = out.size();
    size_t J = out[0].size();
    for (size_t i = 0; i < I; ++i) {
        for (size_t j = 0; j < J; ++j) {
            cout << out[i][j];
        }
        cout << endl;
    }
    testCase++;
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<char> > in;
    for (int i = 0; i < N; ++i) {
        input(&in);
        vector<vector<char> > out;
        bool cor = solve(in, &out);
        output(cor, out);
    }
    return 0;
}
