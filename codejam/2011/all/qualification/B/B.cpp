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

struct Magic {
    char fst;
    char snd;
    char result;
};

struct Opposite {
    char fst;
    char snd;
};

void doMagic(vector<char>* in, const Magic& m) {
    size_t s = in->size();
    if (s <= 1) {
        return;
    }
    if (
      (((*in)[s-1] == m.fst) && ((*in)[s-2] == m.snd)) ||
      (((*in)[s-1] == m.snd) && ((*in)[s-2] == m.fst))
      ) {
        in->pop_back();
       in->pop_back();
      in->push_back(m.result);
    }
}

void doOpposite(vector<char>* in, const Opposite& o) {
    if (in->back() == o.fst) {
        for (size_t i = 0; i < in->size(); ++i) {
            if ((*in)[i] == o.snd) {
                in->clear();
                return;
            }
        }
    }
    if (in->back() == o.snd) {
        for (size_t i = 0; i < in->size(); ++i) {
            if ((*in)[i] == o.fst) {
                in->clear();
                return;
            }
        }
    }
}


vector<char> solve(const vector<char>& in,
        const vector<Magic>& magics,
        const vector<Opposite>& opps) {
    vector<char> res;
    for (size_t i = 0; i < in.size(); ++i) {
        res.push_back(in[i]);
        for (size_t j = 0; j < magics.size(); ++j) {
            doMagic(&res, magics[j]);
        }
        for (size_t k = 0; k < opps.size(); ++k) {
            doOpposite(&res, opps[k]);
        }
    }
    return res;
}

void input (vector<char>* in,
        vector<Magic>* magics,
        vector<Opposite>* opps) {
    size_t m_s, o_s, in_s;

    cin >> m_s;
    *magics = vector<Magic>(m_s);
    Magic m;
    for (int i = 0; i < m_s; ++i) {
        cin >> m.fst >> m.snd >> m.result;
        magics->push_back(m);
    }

    cin >> o_s;
    *opps = vector<Opposite>(o_s);
    Opposite o;
    for (int i = 0; i < o_s; ++i) {
        cin >> o.fst >> o.snd;
        opps->push_back(o);
    }

    cin >> in_s;
    *in = vector<char>(in_s);
    char c;
    for (int i = 0; i < in_s; ++i) {
        cin >> c;
        (*in)[i] = c;
    }
}

void output(const vector<char>& res) {
    static int testCase = 1;
    cout << "Case #" << testCase << ": [";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" <<  endl;
    testCase++;
}

int main() {
    int N;
    cin >> N;
    
    vector<Magic> mgs;
    vector<Opposite> opps;
    vector<char> in;
    vector<char> res;
    for (int i = 0; i < N; ++i) {
        input(&in, &mgs, &opps);
        res = solve(in, mgs, opps);
        output(res);
    }
    return 0;
}
