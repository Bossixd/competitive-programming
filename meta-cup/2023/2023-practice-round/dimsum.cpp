#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        cout << "Case #" << i + 1 << ": ";

        if (r <= c) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}