#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 3 << '\n';
        return;
    }

    int steps = 2;
    int a = 1, b = 0, c;

    while (a < n) {
        c = a * 2 + 1;
        b = a;
        a = c;
        steps++;
    }

    cout << steps * 2 - 1 << '\n';

    return;
}

int main() {
    int N;
    cin >> N;
    while (N--) solve();
}