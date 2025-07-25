#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

template <typename T>
pair<T, T> mp(const T& first, const T& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s[i] = v[i];
    }

    sort(v.begin(), v.end());

    int sm = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == v[i]) ++sm;

    if (sm == n) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << n - sm << '\n';
        for (int i = 0; i < n; ++i)
            if (s[i] != v[i])
                cout << s[i] << ' ';
        cout << '\n';
    }
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
