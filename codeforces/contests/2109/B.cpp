#include <iostream>
using namespace std;

#define int long long

// cut to the left, right, up, or down of the monster
// left = 0
// right = 1
// up = 2
// down = 3
void mouf(int& n, int& m, int& a, int& b) {
    int choice = -1;
    int mx = -1;
    if ((b - 1) * n > mx) {
        choice = 0;
        mx = (b - 1) * n;
    } if ((m - b) * n > mx) {
        choice = 1;
        mx = (m - b) * n;
    } if ((a - 1) * m > mx) {
        choice = 2;
        mx = (a - 1) * m;
    } if ((n - a) * m > mx) {
        choice = 3;
        mx = (n - a) * m;
    }

    if (choice == 0) {
        m -= b - 1;
        b = 1;
    } else if (choice == 1) {
        m = b;
    } else if (choice == 2) {
        n -= a - 1;
        a = 1;
    } else {
        n = a;
    }
}

void fouad(int& n, int& m, int& a, int& b) {
    a = (n + 1) / 2;
    b = (m + 1) / 2;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int turns = 0;

    while (n != 1 || m != 1) {
        mouf(n, m, a, b);
        // cout << n << ' ' << m << ' ' << a << ' ' << b << '\n';
        fouad(n, m, a, b);
        // cout << n << ' ' << m << ' ' << a << ' ' << b << '\n';
        turns += 1;
    }
    cout << turns << '\n';
}

#undef int

int main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}