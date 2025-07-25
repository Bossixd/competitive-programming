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
    int n, k;
    cin >> n >> k;

    int cnt = 0, b;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (b == 0) {
            ++cur;
        } else {
            cur = 0;
        }

        if (cur == k) {
            ++cnt;
            cur = 0;

            if (++i != n)
                cin >> b;
        }
    }

    cout << cnt << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
