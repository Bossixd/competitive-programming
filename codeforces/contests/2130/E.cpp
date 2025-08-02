#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define int long long

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

int MOD = 998244353;

// Inverse of i (mod p)
int inv(int i) {
    if (i == 1) return 1;
    return MOD - (MOD / i) * inv(MOD % i) % MOD;
}

int c;
int qc;

void query(vector<int> v) {
    qc = 0;
    
    cout << "? " << v.size() << ' ';
    for (auto i : v) {cout << i << ' '; ++qc;}
    cout << '\n';

    cout.flush();

    cin >> c;
}

void query(vector<int>::iterator start, vector<int>::iterator end) {
    qc = 0;

    cout << "? " << end - start << ' ';
    while (start < end) {cout << *(start++) << ' '; ++qc;}
    cout << '\n';

    cout.flush();

    cin >> c;
}

void solve() {
    int n;
    cin >> n;

    vector<int> req(n);
    for (int i = 1; i <= n; ++i)
        req[i - 1] = i;

    // Binary Search to find ()
    int l = 1, r = n;
    int ob = 1, cb = 2;

    query(req.begin(), req.end());

    if (c == 0) {
        int m;
        while (r - l > 1) {
            m = (l + r) / 2;
            query({m, 1});
            if (c == 0)
                l = m;
            else
                r = m;
        }
        cout << "! ";
        for (int i = 0; i < l; ++i)
            cout << ')';
        for (int i = l; i < n; ++i)
            cout << '(';
        cout << '\n';
        cout.flush();
        return;
    }
    
    int par = c;
    int m;
    while (r - l > 1) {
        m = (l + r) / 2;
        query(req.begin() + l - 1, req.begin() + m);
        if (qc == 2 && c == 1) {
            ob = l;
            cb = m;
            break;
        }
        if (c != 0) {
            r = m;
            continue;
        }

        query(req.begin() + m, req.begin() + r);
        if (qc == 2 && c == 1) {
            ob = m + 1;
            cb = r;
            break;
        }
        if (c != 0) {
            l = m + 1;
            continue;
        }

        query({m, m + 1});
        if (c == 1) {
            ob = m;
            cb = m + 1;
            break;
        }
    }

    string s = "";
    for (int i = 1; i <= n - 1; i += 2) {
        query({ob, cb, i, i + 1, cb, cb});
        if (c == 1) {
            s += "))";
        } else if (c == 2) {
            s += ")(";
        } else if (c == 3) {
            s += "()";
        } else if (c == 4) {
            s += "((";
        } else {
            cout << "AAAA NO WAY!\n";
        }
    }

    if (n % 2 != 0) {
        query({ob, n});
        if (c == 1)
            s += ")";
        else
            s += "(";
    }

    cout << "! " << s << '\n';
    cout.flush();
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
