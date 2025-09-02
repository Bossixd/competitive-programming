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
#include <cassert>

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

struct Node {
    int left, right, cur;
};

string s;
vector<Node> nodes(3e6, {0, 0, 0});
int ql, qr;

void build (int id, int l, int r) {
    if (l == r) {
        nodes[id].cur = 0;
        nodes[id].left = 0;
        nodes[id].right = 0;

        if (s[l] == '(')
            nodes[id].right = 1;
        else
            nodes[id].left = 1;
        return;
    }

    int m = l + (r - l) / 2;
    build(id<<1, l, m); build((id<<1) + 1, m + 1, r);
    Node left = nodes[(id<<1)], right = nodes[(id<<1) + 1];

    int pairs = min(left.right, right.left);
    nodes[id].left = left.left + right.left - pairs;
    nodes[id].right = left.right + right.right - pairs;
    nodes[id].cur = left.cur + right.cur + pairs * 2;
}

Node score(int id, int l, int r) {
    if (l >= ql && r <= qr)
        return {nodes[id].left, nodes[id].right, nodes[id].cur};
    if (r < ql || l > qr)
        return {0, 0, 0};
    
    Node* node = &nodes[id];

    int m = l + (r - l) / 2;
    Node left = score(id<<1, l, m);
    Node right = score((id<<1) + 1, m + 1, r);

    int pairs = min(left.right, right.left);
    return {left.left + right.left - pairs, left.right + right.right - pairs, left.cur + right.cur + pairs * 2};
}

void solve() {
    cin >> s;

    int n = s.size();

    s = '-' + s;

    build(1, 1, n);

    int q;
    cin >> q;

    while (q--) {
        cin >> ql >> qr;
        cout << score(1, 1, n).cur << '\n';
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
