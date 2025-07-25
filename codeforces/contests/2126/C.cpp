#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

template <typename T>
pair<T, T> mp(const T& first, const T& second) {
    return make_pair(first, second);
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int cur_height = v[k - 1];

    sort(v.begin(), v.end());
    int cur = lower_bound(v.begin(), v.end(), cur_height) - v.begin();

    int water = 1;

    // for (auto i : v) cout << i << ' ';
    // cout << '\n';

    int last = v[cur];
    // cout << cur << ' ' << last << '\n';
    while (cur != n) {
        while (cur != n && v[cur] == last) ++cur;
        if (cur == n) break;

        // cout << cur << ' ' << v[cur] << ' ' << last << ' ' << water << ' ' << water + v[cur] - last - 1 << '\n';
        if (water + v[cur] - last - 1 >= last + 1) {
            cout << "NO\n";
            return;
        }

        water = water + v[cur] - last;
        last = v[cur];
    }
    cout << "YES\n";

    // cout << "\n\n";
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
