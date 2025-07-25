#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

template <typename T, typename L>
pair<T, L> mp(const T& first, const L& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int mn = v[0];
    int last = 0;
    int lowest = 20000000001;
    int sm = 0;
    // Replace with any and switch to lowest
    for (int i = 1; i < n; ++i) {
        lowest = min(lowest, (mn + v[i]) * (i - last) + sm);
        if (v[i] < mn) {
            sm += mn * (i - last);
            last = i;
        }
    }

    // No Switches && Sibling switch
    mn = v[0];
    sm = v[0];
    for (int i = 1; i < n - 1; ++i) {
        lowest = min(lowest, sm + min(mn, v[i] + v[i + 1]));
        mn = min(mn, v[i]);
        sm += mn;
    }

    lowest = min(lowest, sm + min(mn, v[n - 1]));

    cout << lowest << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
