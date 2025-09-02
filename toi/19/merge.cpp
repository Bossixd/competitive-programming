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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> x(n), s(n), y(m), t(m);

    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> y[i];
    for (int i = 0; i < m; ++i) cin >> t[i];

    for (int i = 1; i < n; ++i)
        s[i] += s[i - 1];
    
    for (int i = 1; i < m; ++i)
        t[i] += t[i - 1];

    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;

        auto transform = [a, b](int val) {
            return a * val + b;
        };

        auto inverse = [a, b](int val) {
            return (int) ((val - b) / a);
        };

        int l = min(x[0], transform(y[0]));
        int r = max(x[x.size() - 1], transform(y[y.size() - 1]));
        while (l < r) {
            int m = l + (r - l) / 2;

            int xp = upper_bound(x.begin(), x.end(), m) - x.begin() - 1;
            int yp = upper_bound(y.begin(), y.end(), inverse(m)) - y.begin() - 1;

            int sum = 0;
            if (xp >= 0) sum += s[xp];
            if (yp >= 0) sum += t[yp];

            if (sum < k)
                l = m + 1;
            else
                r = m;
        }

        cout << l << '\n';
    }
}

#undef int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int N;
    // cin >> N;
    // while (N--)
        solve();
}
