#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    char b;
    bool arr[n];
    int yes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        arr[i] = (b - '0') == 1;
        if (arr[i]) yes++;
    }

    if (yes == n) {
        cout << "YES\n";
        return;
    }

    // for (int i = 0; i < n; ++i)
    //     cout << arr[i] << ' ';
    // cout << '\n';
    
    for (int i = 1; i < n - 1; ++i) {
        if (!arr[i - 1] && !arr[i]) {
            cout << "YES\n";
            return;
        }
    }
    if (!arr[0] && !arr[1]) {
        cout << "YES\n";
        return;
    } else if (!arr[n - 1] && !arr[n - 2]) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

// 0 0 0
// 1 1 1
// 0 0