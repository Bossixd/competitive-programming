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

int MOD = 1000000007;

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

unordered_map<int, unordered_map<int, bool>> mp;
vector<int> frac(2e5 + 5);

int dfs(int cur, int par) {

    // Len Children Logic
    int len_children = 0;
    for (auto &[child, _] : mp[cur]) {
        if (child == par) continue;
        if (mp[child].size() > 1)
            ++len_children;
    }

    // Rec Logic
    int res = 1;
    for (auto &[child, _] : mp[cur]) {
        if (child == par) continue;
        res = (res * dfs(child, cur)) % MOD;
    }

    return (res * frac[mp[cur].size() - 1 - len_children]) % MOD;
}


void solve() {
    int n, m;
    cin >> n >> m;

    int a, b;
    int start_idx = 1;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        mp[a][b] = true;
        mp[b][a] = true;
        if (mp[a].size() > mp[start_idx].size())
            start_idx = a;
        if (mp[b].size() > mp[start_idx].size())
            start_idx = b;
    }

    int start_chains = 0;
    for (auto &[child, _] : mp[start_idx])
        if (mp[child].size() != 1) ++start_chains;
    
    if (start_chains == 0) {
        cout << (frac[mp[start_idx].size()] * 2) % MOD << '\n';
        mp.clear();
        return;
    }

    // cout << start_idx << '\n';

    if (m != n - 1) {
        cout << 0 << '\n';
        mp.clear();
        return;
    }

    unordered_set<int> s;
    queue<int> q;
    s.insert(start_idx);

    int score = 0;
    int chain_cnt = 0;
    for (auto &[child, _] : mp[start_idx]) {
        // cout << child << '\n';
        if (mp[child].size() == 1) {
            ++score;
            continue;
        }

        q.push(child);
        ++chain_cnt;
    }

    if (chain_cnt > 2) {
        cout << 0 << '\n';
        mp.clear();
        return;
    }

    int res = frac[score];
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (s.find(cur) != s.end()) continue;
        s.insert(cur);
        
        score = 0;
        int chain = -1;
        // cout << "cur: " << cur << ' ' << mp[cur].size() << '\n';
        for (auto &[child, _] : mp[cur]) {
            // cout << child << '\n';
            if (mp[child].size() == 1) {
                ++score;
                continue;
            }

            if (s.find(child) != s.end()) continue;

            q.push(child);
            if (chain == -1)
                chain = child;
            else {
                // cout << cur << ' ' << chain << ' ' << child << '\n';
                cout << 0 << '\n';
                mp.clear();
                return;
            }
        }

        res = (res * frac[score]) % MOD;
    }

    cout << (res * 4) % MOD << '\n';

    mp.clear();
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    frac[0] = 1;
    frac[1] = 1;
    for (int i = 2; i <= 2e5 + 3; ++i)
        frac[i] = (frac[i - 1] * i) % MOD;
    
    int N;
    cin >> N;
    while (N--)
        solve();
}
