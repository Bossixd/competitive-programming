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

vector<int> seg, v, pref;

int build(int id, int l, int r) {
    if (l == r)
        return seg[id] = v[l];
    int m = l + (r - l) / 2;
    return seg[id] = max(build((id<<1), l, m), build((id<<1) + 1, m + 1, r));
}

int fl, fr, fe;

int gmx(int id, int l, int r) {
    if (seg[id] < fe || r < fl || l > fr)
        return -1e10;
    
    if (l >= fl && r <= fr)
        return seg[id];
    
    int m = l + (r - l) / 2;
    int res = max(gmx((id<<1), l, m), gmx((id<<1) + 1, m + 1, r));
    return res;
}

void solve() {
    int n, s, x;
    cin >> n >> s >> x;

    fe = x;

    v = vector<int>(n + 5);
    pref = vector<int>(n + 5);
    seg = vector<int>(n * 4 + 5, 0);
    unordered_map<int, vector<int>> mp;

    v[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + v[i];
        mp[pref[i]].push_back(i);
    }

    // sort mp and binary search to find starting and ending positions
    // Create pairs of max_value and position to see what end position is
    // No need segment tree

    build(1, 1, n);

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto c : mp[s + pref[i - 1]]) {
            if (c < i) continue;
            fl = i, fr = c;
            if (gmx(1, 1, n) == x)
                ++cnt;
        }
    }
    cout << cnt << '\n';
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
