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

struct Prob {
    int real, inverse;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(4));
    vector<Prob> dp(200005, {0, 0});

    dp[0] = {1, 1};

    int l, r, p, q;
    for (int i = 0; i < n; ++i)
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];

    // sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
    //     return a[0] < b[0];
    // });

    // int last = 0, cur = 0;
    // for (auto i : v) {
    //     if (i[3] - i[2] == 0) {
    //         if (cur >= i[0]) {
    //             cout << 0 << '\n';
    //             return;
    //         }
    //         last = i[0];
    //         cur = i[1];
    //     }
    // }

    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    unordered_set<int> s;

    int P = 1;
    for (int i = 0; i < n; ++i) {
        cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << ' ' << v[i][3] << '\n';
        // cout << dp[v[i][1]].real << ' ' << dp[v[i][1]].inverse << '\n';
        int real = dp[v[i][0] - 1].real * v[i][2];
        int inverse = dp[v[i][0] - 1].inverse * (v[i][3] - v[i][2]);
        // cout << real << ' ' << inverse << '\n';
        // if (real != 0 && inverse != 0 && dp[v[i][1]].inverse == 0) {
        //     dp[v[i][1]].inverse = 1;
        // }

        if (real != 0 && inverse != 0 && dp[v[i][1]].inverse == 0) {
            dp[v[i][1]].inverse = 1;
        }

        if (s.find(v[i][0] - 1) == s.end()) {
            dp[v[i][1]].real = (dp[v[i][1]].real * inverse + dp[v[i][1]].inverse * real) / gcd(dp[v[i][1]].inverse, inverse) % MOD;
            dp[v[i][1]].inverse = dp[v[i][1]].inverse * inverse / gcd(dp[v[i][1]].inverse, inverse) % MOD;
        }

        s.insert(v[i][0] - 1);

        cout << dp[v[i][1]].real << ' ' << dp[v[i][1]].inverse << '\n';
        cout << '\n';

        P *= v[i][3];
    }

    cout << dp[m].real << ' ' << P << '\n';

    cout << dp[m].real * (inv(P) % MOD) % MOD << '\n';
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
