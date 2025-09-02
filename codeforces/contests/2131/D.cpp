#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>

using namespace std;

#define int long long

int MOD = 998244353;

// Layers and adds ranges in O(N)
// Accumulates ranges onto a difference array, then pushes then onto a vector in O(N)
struct DifferenceArray {
    vector<int> v;
    DifferenceArray(int n): v(n, 0) {};

    // O(1)
    void add(int l, int r, int val) {
        if (r < l) return;
        v[l] += val;
        v[r + 1] -= val;
    }

    // O(N)
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

// Creates a pair of multisets where |upper.size() - lower.size()| <= 1
// Multisets are ordered
struct BalancedLowerUpperMultiset {
    multiset<int> lower, upper;

    // O(1)
    void balance() {
        while (lower.size() > upper.size()) {
            upper.insert(*lower.rbegin());
            lower.erase(lower.find(*lower.rbegin()));
        }
        while (upper.size() > lower.size() + 1) {
            lower.insert(*upper.begin());
            upper.erase(upper.find(*upper.begin()));
        }
    }

    // O(N log N)
    void insert(int n) {
        if (upper.size() == 0 || n >= *upper.begin())
            upper.insert(n);
        else
            lower.insert(n);
        balance();
    }

    // O(N log N)
    bool erase(int n) {
        if (lower.find(n) != lower.end())
            lower.erase(lower.find(n));
        else if (upper.find(n) != upper.end())
            upper.erase(upper.find(n));
        else
            return false;
        
        balance();
        return true;
    }

    // O(1)
    int get_lower() {
        if (lower.size() == upper.size()) return *lower.rbegin();
        return lower.size() > upper.size() ? *lower.rbegin() : *upper.begin();
    }

    // O(1)
    int get_upper() {
        if (lower.size() == upper.size()) return *upper.begin();
        return lower.size() < upper.size() ? *upper.begin() : *lower.rbegin();
    }

    // O(N)
    void print() {
        cout << "lwr: ";
        for (auto i : lower)
            cout << i << ' ';
        cout << '\n';
        cout << "upr: ";
        for (auto i : upper)
            cout << i << ' ';
        cout << '\n';
    }
};

// Create pair with dynamic type T and U
template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

// Inverse of i (mod p)
int inv(int i) {
    if (i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}

// Adding "sorting" to structs
/*
bool operator < (const Type& cmp) const {
    return id < cmp.id;
}
*/

vector<unordered_map<int, int>> v(2e5 + 5);
unordered_map<int, unordered_map<int, bool>> edge;
vector<bool> built(2e5 + 5);
vector<int> children(2e5 + 5);

int build(int cur) {
    if (built[cur]) return children[cur];
    built[cur] = true;
    
    if (edge[cur].size() == 1)
        return children[cur] = 1;

    for (auto &[child, _] : edge[cur]) {
        if (built[child]) continue;
        int child_score = build(child);
        children[cur] += child_score;
        v[cur][child] = child_score;
    }

    return children[cur];
}

void build2(int cur, int par) {
    if (built[cur]) return;
    built[cur] = true;

    v[cur][par] = children[par] - v[par][cur];
    children[cur] += v[cur][par];

    for (auto &[child, _] : edge[cur])
        build2(child, cur);
}

void solve() {
    int n;
    cin >> n;

    edge.clear();
    fill(v.begin(), v.begin() + n + 2, unordered_map<int, int>());
    fill(built.begin(), built.begin() + n + 2, false);
    fill(children.begin(), children.begin() + n + 2, 0);

    int a, b, mx_idx = 1;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        edge[a][b] = true;
        edge[b][a] = true;
        if (edge[a].size() > edge[mx_idx].size())
            mx_idx = a;
        if (edge[b].size() > edge[mx_idx].size())
            mx_idx = b;
    }

    built[mx_idx] = true;
    for (auto &[child, _] : edge[mx_idx]) {
        int child_score = build(child);
        children[mx_idx] += child_score;
        v[mx_idx][child] = child_score;
    }

    fill(built.begin(), built.end(), false);

    built[mx_idx] = true;
    for (auto &[child, _] : edge[mx_idx])
        build2(child, mx_idx);

    int mn = 1e18;
    for (int i = 1; i <= n; ++i) {
        int res = 0;
        for (auto p : v[i]) {
            if (edge[p.first].size() == 1) continue;
            res += p.second;
        }
        mn = min(mn, res);
    }

    cout << mn << '\n';
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while (N--)
        solve();
}
