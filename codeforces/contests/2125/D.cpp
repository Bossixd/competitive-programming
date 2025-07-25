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

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

int MOD = 998244353;

int inv(int i) {
    if (i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(4));
    vector<vector<pair<int, int>>> dp(200005);

    int l, r, p, q;
    for (int i = 0; i < n; ++i)
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];

    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    int last = 0, cur = 0;
    for (auto i : v) {
        if (i[3] - i[2] == 0) {
            if (cur >= i[0]) {
                cout << 0 << '\n';
                return;
            }
            last = i[0];
            cur = i[1];
        }
    }

    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    dp[0].push_back({1, 1});

    int L = 1, P = 1;
    for (int i = 0; i < n; ++i) {
        for (auto pr : dp[v[i][0] - 1]) {
            dp[v[i][1]].push_back({(pr.first * v[i][2]) % MOD, (pr.second * ((v[i][3] - v[i][2] == 0) ? 1 : (v[i][3] - v[i][2]))) % MOD});
        }
        
        if (v[i][3] - v[i][2] != 0) {
            L *= (v[i][3] - v[i][2]);
            L %= MOD;
        }

        P *= v[i][3];
        P %= MOD;
    }

    int total = 0;
    for (auto i : dp[m]) {
        total += (((L * i.first) % MOD) / i.second) % MOD;
        total %= MOD;
    }

    cout << total << ' ' << P << '\n';

    cout << total * (inv(P) % MOD) % MOD << '\n';
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int N;
    // cin >> N;
    // while (N--)
        solve();
}
