#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define int long long

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    int a, b, c, d;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        if (a > c)
            cnt += a - c;
        if (b > d)
            cnt += min(a, c) + b - d;
    }

    cout << cnt << '\n';
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
