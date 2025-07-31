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

bool last_r = false;

void printL() {
    if (!last_r)
        cout << "L";
    last_r = false;
}

void printR() {
    cout << "R";
    last_r = true;;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int l = 1, r = n - 1;
    cout << "L";
    while (l <= r) {
        if (v[l - 1] < v[l]) {
            if (v[l] > v[r]) {
                cout << "L";
                ++l;
                if (!(l <= r)) break;
                cout << "R";
                --r;
            } else {
                cout << "R";
                --r;
                if (!(l <= r)) break;
                cout << "L";
                ++l;
            }
        } else {
            if (v[l] < v[r]) {
                cout << "L";
                ++l;
                if (!(l <= r)) break;
                cout << "R";
                --r;
            } else {
                cout << "R";
                --r;
                if (!(l <= r)) break;
                cout << "L";
                ++l;
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
    cin >> N;
    while (N--)
        solve();
}
