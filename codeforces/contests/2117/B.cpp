#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int limi = n / 2;

    if (n % 2 == 1) limi++;
    
    for (int i = 0; i < limi; ++i)
        cout << i * 2 + 1 << ' ';
    for (int i = n / 2; i >= 1; --i)
        cout << i * 2 << ' ';
    cout << '\n';
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
