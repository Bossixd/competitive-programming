#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

template <typename T, typename L>
pair<T, L> mp(const T& first, const L& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int x = 1, b;
    for (int i = 1; i < n; ++i) {
        if (v[i] / v[i - 1] * v[i - 1] != v[i]) {
            b = v[i - 1] / gcd(v[i], v[i - 1]);
            x = x * b / gcd(b, x);
        }
    }
    cout << x << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
