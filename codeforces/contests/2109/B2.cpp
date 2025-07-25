#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<pair<int, int>> rec({
        make_pair(a, m), make_pair(n - a + 1, m),
        make_pair(n, b), make_pair(n, m - b + 1)
    });

    int ans = n + m;

    for (auto &[n1, m1] : rec) {
        int turns = 0;
        while (n1 != 1) {
            n1 = (n1 + 1) / 2;
            turns++;
        }
        
        while (m1 != 1) {
            m1 = (m1 + 1) / 2;
            turns++;
        }
        ans = min(ans, turns);
    }
    cout << 1 + ans << '\n';
}

#undef int

int main() {
    int n;
    cin >> n;
    while (n--)
        solve();
}