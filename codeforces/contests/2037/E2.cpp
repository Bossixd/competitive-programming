#include <iostream>
#include <list>
#include <vector>
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

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1, -1);

    int score = 0, b;
    for (int i = 2; i <= n; ++i) {
        cout << "? " << 1 << ' ' << i << '\n';
        cout.flush();
        cin >> b;
        if (b > score) {
            v[i] = 1;
            if (score == 0) {
                for (int j = 1; j < i - b; ++j)
                    v[j] = 1;
                for (int j = i - b; j < i; ++j)
                    v[j] = 0;
            }
        } else
            v[i] = 0;
        score = b;
    }

    if (score == 0) {
        cout << "! IMPOSSIBLE\n";
        cout.flush();
        return;
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << (v[i] == -1 ? 0 : v[i]);
    cout << '\n';
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
