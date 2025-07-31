#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define int long long

struct DifferenceArray {
    vector<int> v;
    DifferenceArray(int n): v(n, 0) {};

    void add(int l, int r, int val) {
        if (r < l) return;
        v[l] += val;
        v[r + 1] -= val;
    }

    void push(vector<int>& vec) {
        int n = v.size();
        int m = vec.size();
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            sm += v[i];
            v[i] = 0;
            if (i < m)
                vec[i] += sm;
        }
    }
};

// Create pair with dynamic type T and U
template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

int MOD = 998244353;

// Inverse of i (mod p)
int inv(int i) {
    if (i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}

string strip(string s) {
    int n = s.size();
    string res = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            if (i < n - 3 &&
                s[i + 1] == 'B' &&
                s[i + 2] == 'A' &&
                s[i + 3] == 'B') {
                i += 3;
                continue;
            } else if (i < n - 1 && s[i + 1] == 'A') {
                i += 1;
                continue;
            }
        } else if (s[i] == 'B') {
            if (i < n - 3 &&
                s[i + 1] == 'C' &&
                s[i + 2] == 'B' &&
                s[i + 3] == 'C') {
                i += 3;
                continue;
            } else if (i < n - 2 &&
                s[i + 1] == 'A' &&
                s[i + 2] == 'B') {
                i += 2;
                res += 'A';
                continue;
            } else if (i < n - 1 && s[i + 1] == 'B') {
                i += 1;
                continue;
            }
        } else if (s[i] == 'C') {
            if (i < n - 2 &&
                s[i + 1] == 'B' &&
                s[i + 2] == 'C') {
                i += 2;
                res += 'B';
                continue;
            } else if (i < n - 1 && s[i + 1] == 'C') {
                i += 1;
                continue;
            }
        }
        res += s[i];
    }
    return res;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    string s1b = strip(s1);
    while (s1 != s1b) {
        s1 = s1b;
        s1b = strip(s1);
    }

    string s2b = strip(s2);
    while (s2 != s2b) {
        s2 = s2b;
        s2b = strip(s2);
    }

    if (s1.size() != s2.size()) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while (N--)
        solve();
}
