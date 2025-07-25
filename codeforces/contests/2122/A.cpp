#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

template <typename T, typename U>
pair<T, U> mp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int n, m;
    cin >> n >> m;

    if ((n > 2 && m != 1)|| (m > 2 && n != 1))
        cout << "Yes\n";
    else
        cout << "No\n";
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
