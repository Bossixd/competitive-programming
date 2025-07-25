#include <iostream>

using namespace std;

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    // cout << a << ' ' << b << ' ' << x << ' ' << y << '\n';

    if (a - b == 1 && a % 2 == 1) {
        cout << y << '\n';
        return;
    }

    if (a > b) {
        cout << -1 << '\n';
        return;
    }

    if (x < y) {
        cout << (b - a) * x << '\n';
    } else {
        cout << ((a % 2 == 1) ? ((b - a + 1) / 2 * x + (b - a) / 2 * y) : ((b - a) / 2 * x + (b - a + 1) / 2 * y)) << '\n';
    }
}

int main() {
    int N;
    cin >> N;
    while (N--){
        solve();
        // cout << '\n';
    }
}
