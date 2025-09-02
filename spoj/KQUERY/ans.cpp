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

int MOD = 998244353;

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

struct Query {
    int k, l, r, idx;

    bool operator < (const Query& cmp) const {
        return k < cmp.k;
    }
};

vector<pair<int, int>> v;
vector<int> scores(3e6, 0);
int ql, qr;

int update(int id, int l, int r, int u) {
    if (!(u >= l && u <= r))
        return scores[id];
    
    if (l == r)
        return scores[id] = scores[id] - 1;
    
    int m = l + (r - l) / 2;
    return scores[id] = update((id<<1), l, m, u) + update((id<<1) + 1, m + 1, r, u);
}

int score(int id, int l, int r) {
    if (l >= ql && r <= qr)
        return scores[id];

    if (r < ql || l > qr)
        return 0;
    
    int m = l + (r - l) / 2;
    int left = score((id<<1), l, m);
    int right = score((id<<1) + 1, m + 1, r);

    return left + right;
}

void solve() {
    int n;
    cin >> n;

    v = vector<pair<int, int>>(n);
    int b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        v[i] = mkp(b, i + 1);
    }

    sort(v.begin(), v.end());

    int q;
    cin >> q;

    vector<Query> queries;
    vector<int> res(q);
    int l, r, k, idx = 0;
    while (q--) {
        cin >> l >> r >> k;
        queries.push_back({k, l, r, idx++});
    }

    sort(queries.begin(), queries.end());

    int cur = 0;
    for (auto query : queries) {
        while (cur < n && v[cur].first <= query.k) {
            update(1, 1, n, v[cur].second);
            ++cur;
        }

        ql = query.l;
        qr = query.r;

        res[query.idx] = qr - ql + 1 + score(1, 1, n);
    }
    
    for (auto i : res)
        cout << i << '\n';
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int N;
    // cin >> N;
    // while (N--)
        solve();
}
