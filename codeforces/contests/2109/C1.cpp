#include <iostream>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int out;
    int x;

    cout << "digit" << '\n';
    cin >> x;
    cout << "digit" << '\n';
    cin >> x;
    cout << "add -8" << '\n';
    cin >> x;
    cout << "add -4" << '\n';
    cin >> x;
    cout << "add -2" << '\n';
    cin >> x;
    cout << "add -1" << '\n';
    cin >> x;
    cout << "add " << n - 1 << '\n';
    cin >> x;
    cout << "!" << '\n';
    cin >> x;
}

#undef int

int main() {
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}