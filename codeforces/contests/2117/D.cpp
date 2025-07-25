#include <iostream>
#include <unordered_set>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int a, b;
    int diff;
    cin >> a >> b;
    diff = a - b;

    int f = a;

    for (int i = 2; i < n; ++i) {
        a = b;
        cin >> b;
        if (a - b != diff) {
            // cout << a << ' ' << b << ' ' << a - b << '\n';
            cout << "NO\n";
            for (int j = i + 1; j < n; ++j) cin >> b;
            return;
        }
    }

    int l = b;

    // cout << abs(l - n * f) << ' ' << abs(1 - n * n) << '\n';

    if (abs(l - n * f) % abs(1 - n * n) != 0) {
        cout << "NO\n";
        return;
    }

    int y = (l - n * f) / (1 - n * n);
    // cout << "Y: " << y << '\n';

    int x = f - y * n;
    // cout << "X: " << x << '\n';

    if (x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }


    cout << "YES\n";
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
