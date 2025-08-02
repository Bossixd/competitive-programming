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
#include <set>

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

struct BalancedLowerUpperMultiset {
    multiset<int> lower, upper;

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

    void insert(int n) {
        if (upper.size() == 0 || n >= *upper.begin())
            upper.insert(n);
        else
            lower.insert(n);
        balance();
    }

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

    int get_lower() {
        if (lower.size() == upper.size()) return *lower.rbegin();
        return lower.size() > upper.size() ? *lower.rbegin() : *upper.begin();
    }

    int get_upper() {
        if (lower.size() == upper.size()) return *upper.begin();
        return lower.size() < upper.size() ? *upper.begin() : *lower.rbegin();
    }

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

int q;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n + 5, 0);
    int mn_val = 1000000000, mx_val = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        mn_val = min(mn_val, v[i]);
        mx_val = max(mx_val, v[i]);
    }

    int l, m, r;
    int mini;
    int mn, mx;
    int ccm, ccl, ccr;
    int cmx, cmxl, cmxr;
    int cmn, cmnl, cmnr;

    vector<int> b(n + 5, 0), s(n + 5, 0);

    l = mn_val, r = mx_val + 1;
    while (l <= r) {
        m = (l + r) / 2;
        for (int i = 1; i <= n; ++i)
            b[i] = b[i - 1] + (v[i] >= m ? 1 : -1);
        
        mn = 0, mx = -1;
        mini = 0;

        for (int i = k; i <= n; ++i) {
            if (b[i - k] < mn) {
                mn = b[i - k];
                mini = i - k + 1;
            }
            if (b[i] - mn > mx) {
                mx = b[i] - mn;
                cmx = m;
                cmxl = mini;
                cmxr = i;
            }
        }

        if (mx >= 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    l = mn_val, r = mx_val;

    while (l <= r) {
        m = (l + r) / 2;
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + (v[i] <= m ? 1 : -1);
        
        mn = 0, mx = -1;
        mini = 0;

        for (int i = k; i <= n; ++i) {
            if (s[i - k] < mn) {
                mn = s[i - k];
                mini = i - k + 1;
            }
            if (s[i] - mn > mx) {
                mx = s[i] - mn;
                cmn = m;
                cmnl = mini;
                cmnr = i;
            }
        }

        if (mx >= 0) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cmnl = max(1LL, cmnl);
    cmnr = max(1LL, cmnr);
    cmxl = max(1LL, cmxl);
    cmxr = max(1LL, cmxr);

    mx = cmn;

    BalancedLowerUpperMultiset blum;
    l = cmnl, r = cmnr;


    for (int i = l; i <= r; ++i)
        blum.insert(v[i]);

    cout << cmx - cmn + 1 << '\n';

    for (int i = mx; i <= blum.get_upper(); ++i)
        cout << i << ' ' << l << ' ' << r << '\n';
    mx = blum.get_upper();

    int mmm = 0;
    
    if (cmnr <= cmxr) {
        while (r != cmxr) {
            if (r < cmxr) {
                ++r;
                blum.insert(v[r]);
            } else {
                blum.erase(v[r]);
                --r;
            }

            if (blum.get_upper() > mx) {
                for (int i = mx + 1; i <= blum.get_upper(); ++i)
                    cout << i << ' ' << l << ' ' << r << '\n';
                mx = blum.get_upper();
            }
        }

        while (l != cmxl) {
            if (l < cmxl) {
                blum.erase(v[l]);
                ++l;
            } else {
                --l;
                blum.insert(v[l]);
            }

            if (blum.get_upper() > mx) {
                for (int i = mx + 1; i <= blum.get_upper(); ++i)
                    cout << i << ' ' << l << ' ' << r << '\n';
                mx = blum.get_upper();
            }
        }
    } else {
        while (l != cmxl) {
            if (l < cmxl) {
                blum.erase(v[l]);
                ++l;
            } else {
                --l;
                blum.insert(v[l]);
            }

            if (blum.get_upper() > mx) {
                for (int i = mx + 1; i <= blum.get_upper(); ++i)
                    cout << i << ' ' << l << ' ' << r << '\n';
                mx = blum.get_upper();
            }
        }
        
        while (r != cmxr) {
            if (r < cmxr) {
                ++r;
                blum.insert(v[r]);
            } else {
                blum.erase(v[r]);
                --r;
            }

            if (blum.get_upper() > mx) {
                for (int i = mx + 1; i <= blum.get_upper(); ++i)
                    cout << i << ' ' << l << ' ' << r << '\n';
                mx = blum.get_upper();
            }
        }
    }
    cout << '\n';
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    q = 1;
    cin >> N;
    while (N--) {
        solve();
        ++q;
    }
}