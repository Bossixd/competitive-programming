#include <iostream>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int cur;
    cin >> cur;

    int last = cur;
    int last_index = 1;
    
    int mn = (n - last_index) * cur;

    for (int i = 2; i <= n; ++i) {
        cin >> cur;
        if (cur == last) {
            mn = min(mn, (n - (i - last_index) - 1) * cur);
        } else {
            last = cur;
            last_index = i;
            mn = min(mn, (n - 1) * cur);
        }
    }

    cout << mn << '\n';

    return;
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--) solve();
}