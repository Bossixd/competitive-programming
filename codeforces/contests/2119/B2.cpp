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
    int n, px, py, qx, qy;
    cin >> n >> px >> py >> qx >> qy;

    qx -= px;
    qy -= py;

    double d = qx * qx + qy * qy;

    int b;
    int mx = -1;
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        mx = max(mx, b);
        sm += b;
    }

    if (d <= sm * sm && d >= max(0LL, (2 * mx - sm)) * (2 * mx - sm)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
