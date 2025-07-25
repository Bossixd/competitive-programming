#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

template <typename T>
pair<T, T> mp(const T& first, const T& second) {
    return make_pair(first, second);
}

void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n % 2 == 1) {
        cout << l << '\n';
    } else {
        if (l == r) {
            cout << -1 << '\n';
        } else {
            int mask = 1 << 60;
            mask -= 1;
            int b = l;
            int c = 1;
            while (((b >> 1) & mask) != 0) {
                b = b >> 1;
                c = c << 1;
            }
            c = c << 1;
            if (c <= r && n >= 4) {
                if (k >= n - 1) {
                    cout << c << '\n';
                } else {
                    cout << l << '\n';
                }
            } else {
                cout << -1 << '\n';
            }
        }
    }
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
