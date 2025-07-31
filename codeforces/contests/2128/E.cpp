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
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int mn_val = 1000000000, mx_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mn_val = min(mn_val, v[i]);
        mx_val = max(mx_val, v[i]);
    }

    int l, m, r;
    int cm, cl, cr;
    int n, k;

    l = mn_val, r = mx_val, m;
    cm = -1, cl = -1, cr = -1;
    vector<int> b(n);

    m = (l + r) / 2;

    while (r - l > 1) {
        m = (l + r) / 2;
        b[0] = v[0] >= m ? 1 : -1;
        for (int i = 1; i < n; ++i)
            b[i] = b[i - 1] + (v[i] >= m ? 1 : -1);
        
        int mn = 0, mx = -1;
        for (int i = k; i < n; ++i) {
            mn = min(mn, b[i - k]);
            mx = max(mx, b[i] - mn);
        }

        if (mx >= 0) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << cm << ' ' << max(1LL, cl + 1) << ' ' << max(1LL, cr + 1) << '\n';
    // cout << '\n';
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