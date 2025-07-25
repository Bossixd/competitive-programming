#include <iostream>

using namespace std;

void solve() {
    int n, x, b;
    cin >> n >> x;

    int start = -1;
    int end = -1;

    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (b == 1 && start == -1) start = i;
        if (b == 1) end = i;
    }

    if (end - start < x) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
