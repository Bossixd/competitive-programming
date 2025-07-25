#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define int long long

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    string s;
    cin >> s;

    string res = "";
    int n = s.size(), tcnt = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'T')
            res += 'T';
    for (int i = 0; i < n; ++i)
        if (s[i] != 'T')
            res += s[i];
    
            cout << res << '\n';
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
