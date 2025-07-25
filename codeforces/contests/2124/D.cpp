#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

#define int long long

template <typename T, typename L>
pair<T, L> mp(const T& first, const L& second) {
    return make_pair(first, second);
}

// void solve() {
//     int n, k;
//     cin >> n >> k;

//     int d = n + 1 - k;
//     int dp[n][n];
//     int nums[n];
//     for (int i = 0; i < n; ++i) cin >> nums[i];

//     for (int i = 0; i < n; ++i) dp[i][i] = 0;
//     for (int i = 0; i < n - 1; ++i) dp[i + 1][i] = 0;


//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             dp[i][j] = 0;
//             cout << dp[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     for (int l = 2; l < n; ++l) {
//         for (int i = 0; i < n - l; ++i) {
//             dp[i][i + l - 1] = 0;
//             cout << i << ' ' << l << '\n';
//             for (int j = 0; j < l - 1; ++j) {
//                 cout << "(" << i << ", " << i + j << "), (" << i + j + 1 << ", " << i + l - 1 << ")\n";
//                 dp[i][i + l - 1] = max(dp[i][i + l - 1], dp[i][i + j] + dp[i + j + 1][i + l - 1]);
//             }
//             if (nums[i] == nums[i + l - 1]) dp[i][i + l - 1] = max(dp[i][i + l - 1], dp[i + 1][i + l - 2] + 1);
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << dp[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     cout << dp[0][n - 1] << '\n';
// }

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n), s(n);
    unordered_map<int, int> mp, deleted;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s[i] = v[i];
        ++mp[v[i]];
    }

    sort(s.begin(), s.end());

    int e = 0, o = 0;

    for (auto &[i, c] : mp) {
        if (c % 2 == 0) ++e;
        else ++o;
    }

    for (int i = k - 1; i <= n; ++i) {
        if (o <= 1) {
            int l = 0, r = n - 1;
            unordered_map<int, int> d = deleted;
            bool op = false, found = true;
            while (l != r) {
                op = false;
                if (v[l] == v[r]) {
                    ++l; --r;
                    op = true;
                } else {
                    if (d[v[l]] != 0) {
                        --d[v[l]]; ++l;
                        op = true;
                    }
                    if (d[v[r]] != 0) {
                        --d[v[r]]; --r;
                        op = true;
                    }
                }
                if (!op) {
                    found = false;
                    break;
                }
            }

            if (found) {
                cout << "YES\n";
                return;
            }
        }

        deleted[s[i]]++;
        if ((mp[s[i]] - deleted[s[i]]) % 2 == 0) {
            ++e; --o;
        } else {
            ++o; --e;
        }
    }

    cout << "NO\n";
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
