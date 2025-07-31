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
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int last_max_idx = 0, last_max = 2;

    vector<vector<int>> longest_pref(2, vector<int>(n, 0));
    vector<int> lis;
    lis.push_back(v[0]);
    longest_pref[0][0] = 2;
    longest_pref[1][0] = 2;
    for (int i = 1; i < n; ++i) {
        // cout << i << " : " << last_max_idx << ' ' << last_max << ' ' << 2 * n - v[i] << ' ' << 2 * n - v[last_max_idx] << '\n';
        if (2 * n - v[i] > 2 * n - v[last_max_idx]) {
            longest_pref[1][i] = last_max + 2;
            last_max_idx = i;
        }

        longest_pref[1][i] = max(longest_pref[1][i], ((int) lis.size() + 1) * 2);
        if (longest_pref[1][i] > last_max) {
            last_max_idx = i;
            last_max = longest_pref[1][i];
        }

        if (v[i] > lis[lis.size() - 1])
            lis.push_back(v[i]);
        else
            *lower_bound(lis.begin(), lis.end(), v[i]) = v[i];

        longest_pref[0][i] = lis.size() * 2;
    }

    // cout << '\n';

    vector<vector<int>> longest_suff(2, vector<int>(n, 0));
    lis.clear();
    lis.push_back(v[n - 1]);
    longest_suff[0][n - 1] = 1;
    longest_suff[1][n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        longest_suff[1][i] = lis.size() + 1;

        if (v[i] > lis[lis.size() - 1])
            lis.push_back(v[i]);
        else
            *lower_bound(lis.begin(), lis.end(), v[i]) = v[i];

        longest_suff[0][i] = lis.size();
    }

    // for (int i = 0; i < n; ++i)
    //     cout << longest_pref[0][i] << ' ';
    // cout << '\n';

    // for (int i = 0; i < n; ++i)
    //     cout << longest_pref[1][i] << ' ';
    // cout << '\n';

    // cout << '\n';

    // for (int i = 0; i < n; ++i)
    //     cout << longest_suff[0][i] << ' ';
    // cout << '\n';

    // for (int i = 0; i < n; ++i)
    //     cout << longest_suff[1][i] << ' ';
    // cout << '\n';

    // cout << '\n';

    int mx_lis = 0, mx_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (longest_pref[1][i] + longest_suff[1][i] > mx_lis) {
            mx_lis = longest_pref[1][i] + longest_suff[1][i];
            mx_idx = i;
        }
    }

    // cout << mx_idx << '\n';
    // cout << '\n';

    int i;
    for (i = 0; i < n; ++i) {
        if (longest_pref[1][i] != longest_pref[0][i]) {
            v[i] = 2 * n - v[i];
        }
    }

    for (; i < n; ++i) {
        // if (longest_suff[1][i] != longest_suff[0][i]) {
            v[i] = 2 * n - v[i];
        // }
    }

    // for (auto i : v) cout << i << ' ';
    // cout << '\n';

    int score = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[i] > v[j]) score++;
        }
    }
    cout << score << '\n';
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
