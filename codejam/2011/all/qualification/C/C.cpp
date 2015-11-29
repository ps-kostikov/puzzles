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

int sum (int x, int y) {
    int s = 0;
    for (int i = 0; i < 23; ++i) {
        int r = 1 << i;
        int x1 = x & r;
        int y1 = y & r;
        int tmp = x1 ^ y1;
        s += tmp;
    }
    return s;
}

int solve(vector<int>& in) {
    int s = 0;
    int ss = 0;
    for (size_t i = 0; i < in.size(); ++i) {
        s = sum (s, in[i]);
        ss += in[i];
    }
    if (s != 0) {
        return -1;
    }
    std::sort(in.begin(), in.end());
    return ss - in[0];
}

void input(vector<int>* in) {
    size_t size;
    cin >> size;
    *in = vector<int> (size, 0);
    int number;
    for( size_t i = 0; i < size; ++i) {
        cin >> number;
        (*in)[i] = number;
    }

}

void output(int sum) {
    static int testCase = 1;
    cout << "Case #" << testCase << ": ";
    if (sum == -1) {
        cout << "NO";
    } else {
        cout << sum;
    }
    cout << endl;
    testCase++;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> in;
    for (int i = 0; i < N; ++i) {
        input(&in);
        int sum = solve(in);
        output(sum);
    }
    return 0;
}
