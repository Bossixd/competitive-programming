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

    vector<int> v(n + 5, 0);
    int mn_val = 1000000000, mx_val = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        mn_val = min(mn_val, v[i]);
        mx_val = max(mx_val, v[i]);
    }

    int l, m, r;
    int cm, cl, cr;
    int mini;
    int mn, mx;
    int ccm, ccl, ccr;

    l = mn_val, r = mx_val + 1, m;
    cm = mn_val, cl = -1, cr = -1;
    vector<int> b(n + 5, 0);

    while (l <= r) {
        m = (l + r) / 2;
        for (int i = 1; i <= n; ++i)
            b[i] = b[i - 1] + (v[i] >= m ? 1 : -1);
        
        mn = 0, mx = -1;
        mini = 0;

        for (int i = k; i <= n; ++i) {
            if (b[i - k] < mn) {
                mn = b[i - k];
                mini = i - k + 1;
            }
            if (b[i] - mn > mx) {
                mx = b[i] - mn;
                cm = m;
                cl = mini;
                cr = i;
            }
        }

        if (mx >= 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << cm << ' ' << max(1LL, cl) << ' ' << max(1LL, cr) << '\n';
    cout << '\n';
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