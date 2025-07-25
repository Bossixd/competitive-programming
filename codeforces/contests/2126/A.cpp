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

    int mn = 10;
    while (n != 0) {
        mn = min(mn, n % 10);
        n /= 10;
    }
    cout << mn << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
