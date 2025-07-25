#include <iostream>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) cout << 1;
    for (int i = k; i < n; ++i) cout << 0;
    cout << '\n';
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
