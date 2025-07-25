#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vv(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> vv[i];

    unordered_map<int, unordered_map<int, int>> mp;
    int u, v, c;
    int sm = 0;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> c;
        
        mp[u][v] = c;
        mp[v][u] = c;

        if (vv[u] != vv[v]) sm += c;
    }

    int x;
    for (int i = 0; i < q; ++i) {
        cin >> v >> x;
        for (auto &[j, p] : mp[v]) {
            if (vv[v] == vv[j] && x != vv[j])
                sm += mp[v][j];
            else if (vv[v] != vv[j] && x == vv[j])
                sm -= mp[v][j];
        }
        vv[v] = x;
        cout << sm << '\n';
    }
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
