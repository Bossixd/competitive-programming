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

    vector<vector<int>> pow_brackets = {
        { 1 },
        { 1, 1 },
        { 2, 1 },
        { 3, 1, 1 },
        { 5, 1 },
        { 7, 2, 1 },
        { 10, 3, 2 },
        { 15, 3, 1, 1 },
        { 22, 2 },
        { 31, 5, 1 },
        { 44, 7, 3 },
        { 63, 7, 2, 1 },
        { 90, 1 },
    };
    vector<int> pow_sum = {1LL, 3LL, 7LL, 15LL, 31LL, 63LL, 127LL, 255LL, 511LL, 1023LL, 2047LL, 4095LL, 8191LL};
    for (int i = 0; i < n; i += pow_brackets.size()) {
        vector<int> q;
        for (int pow_idx = 0; pow_idx < min(n - i, (int) pow_brackets.size()); ++pow_idx) {
            for (auto pow_bracket : pow_brackets[pow_idx]) {
                for (int j = 0; j < pow_bracket; ++j) {
                    q.push_back(i + pow_idx + 1);
                    q.push_back(cb);
                }
                q.push_back(cb);
            }
        }
        query(q.begin(), q.end());
        int bin = pow_sum[min((int) pow_brackets.size(), n - i) - 1] - c;
        int cur = 1;
        for (int j = 0; j < min((int) pow_brackets.size(), n - i); ++j) {
            if ((bin & cur) == 0)
                s += '(';
            else
                s += ')';
            cur <<= 1;
        }
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