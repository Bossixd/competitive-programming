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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> va(a), vb(b), vc(c), vd(d);
    for (int i = 0; i < a; ++i)
        cin >> va[i];
    for (int i = 0; i < b; ++i)
        cin >> vb[i];
    for (int i = 0; i < c; ++i)
        cin >> vc[i];
    for (int i = 0; i < d; ++i)
        cin >> vd[i];

    // sort(vd.begin(), vd.end());

    // for (int i = 0; i < a; ++i) {
    //     for (int j = 0; j < b; ++j) {
    //         for (int k = 0; k < c; ++k) {
    //             int cur = va[i] + vb[j] + vc[k];
    //             auto lb = lower_bound(vd.begin(), vd.end(), -cur);
    //             if (lb - vd.begin() >= d)
    //                 continue;
    //             if (*lb != -cur)
    //                 continue;
                
    //             cout << va[i] << ' ' << vb[j] << ' ' << vc[k] << ' ' << *lb << '\n';
    //             return;
    //         }
    //     }
    // }

    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            mp[vc[i] + vd[j]] = mkp(vc[i], vd[j]);

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int cur = va[i] + vb[j];

            auto res = mp.find(-cur);

            if (res == mp.end()) continue;
            
            cout << va[i] << ' ' << vb[j] << ' ' << (*res).second.first << ' ' << (*res).second.second << '\n';
            return;
        }
    }
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