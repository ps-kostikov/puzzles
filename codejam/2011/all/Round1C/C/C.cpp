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

typedef long long ll;

ll NOD (ll x, ll y) {
    ll min = std::min(x, y);
    ll max = std::max(x, y);
    if (min == max || min == 0) {
        return max;
    }
    return NOD(min, max % min);
}

ll NOD (const vector<ll>& v) {
    ll res = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        res =  NOD(res, v[i]);
    }
    return res;
}

ll solve(vector<ll>& in, ll& low, ll& high) {
    std::sort(in.begin(), in.end());
    vector<ll>::iterator it = std::unique(in.begin(), in.end());
    in.resize(it - in.begin());
    
    return -1;
}

void input(vector<ll>* in, ll& low, ll& high) {
    size_t N;
    cin >> N >> low >> high;
    *in = vector<ll> (N);
    for (size_t i = 0; i < N; ++i) {
        cin >> (*in)[i];
    }
}

void output(ll out) {
    static int testCase = 1;
    cout << "Case #" << testCase << ": ";
    if (out == -1) {
        cout << "NO" << endl;
    } else {
        cout << out << endl;
    }
    testCase++;
}

int main() {
    vector<ll> v;
    v.push_back(18);
    v.push_back(24);
    v.push_back(36);
    cout << NOD(v) << endl;
    return 0;
    
    int N;
    cin >> N;

    vector<ll> in;
    ll low, high;
    for (int i = 0; i < N; ++i) {
        input(&in, low, high);
        ll res = solve(in, low, high);
        output(res);
    }
    return 0;
}
