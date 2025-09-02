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

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 5, 0);
    unordered_map<int, unordered_set<int>> edge;
    vector<pair<int, int>> res;
    vector<bool> searched(n + 5, false);

    int a, b;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        ++cnt[a]; ++cnt[b];
        edge[a].insert(b);
        edge[b].insert(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] != 2) continue;
        bool found = true;
        
        for (auto e : edge[i]) {
            if (cnt[e] <= 2)
                found = false;
        }

        if (!found) continue;

        vector<int> buf(cnt[i]);
        int index = 0;

        for (auto e : edge[i])
            buf[index++] = e;

        res.push_back(mkp(2, i));
        res.push_back(mkp(1, i));

        for (auto e : buf) {
            edge[i].erase(e);
            edge[e].erase(i);
            cnt[e]--;
            cnt[i]--;
        }

        searched[i] = true;
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (searched[i]) continue;
        pq.push(mkp(cnt[i], i));
    }

    vector<int> ones;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (cnt[cur.second] != cur.first) {
            pq.push(mkp(cnt[cur.second], cur.second));
            continue;
        }

        if (cur.first > 2) {
            res.push_back(mkp(2, cur.second));
            res.push_back(mkp(1, cur.second));

            vector<int> buf(edge[cur.second].size());
            int index = 0;

            for (auto e : edge[cur.second])
                buf[index++] = e;
            
            for (auto e : buf) {
                edge[cur.second].erase(e);
                edge[e].erase(cur.second);
                cnt[e]--;
                cnt[cur.second]--;
            }
        } else if (cur.first <= 1)
            ones.push_back(cur.second);
    }

    for (int i = 0; i < ones.size(); ++i) {
        if (searched[ones[i]]) continue;
        searched[ones[i]] = true;

        res.push_back(mkp(1, ones[i]));
        int cur = ones[i];
        while (true) {
            int done = true;
            for (auto e : edge[cur]) {
                if (searched[e]) continue;
                searched[e] = true;
                done = false;
                cur = e;
                res.push_back(mkp(1, e));
            }

            if (done) break;
        }
    }

    cout << res.size() << '\n';
    cout << (5.0 / 4.0 * n) << '\n';
    if (res.size() > (5.0 / 4.0 * n))
        while (true);
    for (auto i : res)
        cout << i.first << ' ' << i.second << '\n';
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
