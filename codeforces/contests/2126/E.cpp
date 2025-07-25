#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

template <typename T>
pair<T, T> mp(const T& first, const T& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n), s(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    bool cond = p[0] == s[0];
    for (int i = 1; i < n; ++i) {
        if (p[i - 1] % p[i] != 0) {
            cout << "NO\n";
            return;
        }
        if (s[i] % s[i - 1] != 0) {
            cout << "NO\n";
            return;
        }
        if (p[i] == s[i]) cond = true;
        if (p[i] == s[i - 1]) cond = true;
    }

    if (cond)
        cout << "YES\n";
    else
        cout << "NO\n";
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
