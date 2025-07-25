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

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    int _gcd = gcd(a, b);

    if (a <= k && b <= k) {
        cout << 1 << '\n';
    } else if (a / _gcd <= k && b / _gcd <= k) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
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
