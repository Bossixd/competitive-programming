#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

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

#define int long long

int MOD = 998244353;

// Inverse of i (mod p)
int inv(int i) {
    if (i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}

string strip(string s) {
    int n = s.size();
    stack<char> stk;
    for (auto c : s) {
        if (c == 'B') continue;
        if (!stk.empty() && stk.top() == c)
            stk.pop();
        else
            stk.push(c);
    }
    string res(stk.size(), 'Z');
    int i = stk.size() - 1;
    while (!stk.empty()) {
        res[i--] = stk.top();
        stk.pop();
    }
    return res;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    string s1b = "", s2b = "";
    int c1 = 0, c2 = 0;
    for (auto c : s1) {
        if (c == 'B') ++c1;
        else s1b += c;
    }
    for (auto c : s2) {
        if (c == 'B') ++c2;
        else s2b += c;
    }

    if (c1 % 2 != c2 % 2) {
        cout << "NO\n";
        return;
    }

    if (strip(s1b) != strip(s2b))
        cout << "NO\n";
    else
        cout << "YES\n";
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
