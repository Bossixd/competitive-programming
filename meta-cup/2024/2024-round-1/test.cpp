#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

bool test_case(int t);

int main() {
    int T = 1000;
    int primes[T];
    int idx = 0;
    int last = 2;
    for (int t = 3; t < T; ++t)
        if (test_case(t)) {
            primes[idx++] = t;
            cout << t - last << '\n';
            last = t;
        }
//     set<int> s;
//     for (int i = 0; i < idx; ++i)
//         for (int j = 0; j < i; ++j)
//             s.insert(primes[i] - primes[j]);
//     vector<int> v;
//     for (auto i : s) {
//         v.push_back(i);
//     }
//     sort(v.begin(), v.end());
//     for (auto i : v)
//         cout << i << '\n';
}

bool test_case(int t) {
    for (int i = 2; i * i <= t; ++i) {
        if (t % i == 0) return false;
    }
    return true;
}