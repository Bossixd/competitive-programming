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

unordered_map<int, unordered_set<int>> edges;
unordered_map<int, unordered_map<int, int>> edges_idx;
vector<int> path(3005);
int cur_idx = 0;
unordered_set<int> s, s2;
int mn, mx;

bool dfs_find(int cur) {
    mn = min(mn, cur);
    mx = max(mx, cur);
    if (s.find(cur) != s.end())
        return false;

    s2.insert(cur);
    for (auto next : edges[cur]) {
        if (s2.find(next) != s2.end()) continue;
        if (!dfs_find(next))
            return false;
    }

    return true;
}

bool dfs_path(int cur) {
    s.insert(cur);
    
    if (cur == mx) {
        path[cur_idx++] = cur;
        return true;
    }

    for (auto next : edges[cur]) {
        if (s.find(next) != s.end()) continue;

        path[cur_idx++] = cur;
        if (dfs_path(next))
            return true;
        cur_idx--;
    }

    return false;
}

void solve() {
    int n;
    cin >> n;

    edges.clear();
    edges_idx.clear();
    s.clear();
    s2.clear();

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
        edges_idx[a][b] = i + 1;
        edges_idx[b][a] = i + 1;
    }

    vector<int> res;

    for (auto &[cur_node, s] : edges) {
        if (s.find(cur_node) != s.end()) continue;

        mn = 1000000000;
        mx = 0;
        cur_idx = 0;

        if (!dfs_find(cur_node)) continue;

        dfs_path(mn);

        for (int i = 1; i < cur_idx; ++i)
            res.push_back(edges_idx[path[i - 1]][path[i]]);
    }
    cout << res.size() << '\n';
    for (auto i : res)
        cout << i << ' ';
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
