#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define int long long

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int l, r;
    cin >> l >> r;

    --l;
    int under = (l / 2) + (l / 3) + (l / 5) + (l / 7)
                - (l / 6) - (l / 10) - (l / 14) - (l / 15) - (l / 21) - (l / 35)
                + (l / 30) + (l / 42) + (l / 70) + (l / 105)
                - (l / 210);
    int over = (r / 2) + (r / 3) + (r / 5) + (r / 7)
                - (r / 6) - (r / 10) - (r / 14) - (r / 15) - (r / 21) - (r / 35)
                + (r / 30) + (r / 42) + (r / 70) + (r / 105)
                - (r / 210);
    cout << (r - l) - (over - under) << '\n';
}

#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while (N--)
        solve();
}
