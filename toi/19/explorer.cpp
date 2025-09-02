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

int MOD = 1000000007;

// Inverse of i (mod p)
int inv(int i) {
    if (i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}

vector<unordered_set<int>> mp;
vector<bool> searched;
vector<int> fact(1005);
int ini;

void solve() {
    fact[0] = 1;
    for (int i = 1; i <= 250; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;

    int n;
    cin >> n;

    mp = vector<unordered_set<int>>(n + 5);
    searched = vector<bool>(n + 5, false);

    int a, b;
    cin >> a;
    ini = a;
    for (int i = 1, limi = 2 * n - 1; i < limi; ++i) {
        cin >> b;
        if (mp[a].find(b) == mp[a].end()) {
            mp[a].insert(b);
            mp[b].insert(a);
        }
        a = b;
    }

    stack<int> stk;

    int score = fact[mp[ini].size()];
    searched[ini] = true;
    
    for (auto i : mp[ini])
        stk.push(i);

    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();

        if (searched[cur])
            continue;
        searched[cur] = true;
        
        score = (score * fact[mp[cur].size() - 1]) % MOD;
        
        for (auto i : mp[cur])
            stk.push(i);
    }

    cout << score << '\n';
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
