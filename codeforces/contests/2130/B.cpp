#include <iostream>
#include <list>
#include <vector>
#include <stack>
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

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> v(3, 0);
    int sm = 0, b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        ++v[b];
        sm += b;
    }

    // cout << s << ' ' << sm << '\n';

    if (s < sm) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < v[i]; ++j) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }

    if (s - sm == 1) {
        for (int j = 0; j < v[0]; ++j)
            cout << 0 << ' ';
        for (int j = 0; j < v[2]; ++j)
            cout << 2 << ' ';
        for (int j = 0; j < v[1]; ++j)
            cout << 1 << ' ';
        cout << '\n';
        return;
    }

    cout << -1 << '\n';
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
