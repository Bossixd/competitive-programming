#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a, x, y;
    cin >> a >> x >> y;

    int i = min(x, y), j = max(x, y);
    
    if (a < i || a > j) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
