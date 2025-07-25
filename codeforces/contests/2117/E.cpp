#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    int a[n], b[n];
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int mx = 0;

    unordered_map<int, pair<pair<int, int>, pair<int, int>>> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = make_pair(make_pair(i, -1), make_pair(-1, -1));
        else
            mp[a[i]] = make_pair(make_pair(i, mp[a[i]].first.first), mp[a[i]].second);

        if (mp.find(b[i]) == mp.end())
            mp[b[i]] = make_pair(make_pair(-1, -1), make_pair(i, -1));
        else
            mp[b[i]] = make_pair(mp[b[i]].first, make_pair(i, mp[b[i]].second.first));
    }

    int mxs;

    for (auto &[i, j] : mp) {
        mxs = -1;
        auto &[x, y] = j.first;
        auto &[a, b] = j.second;

        // cout << i << " | " << x << ' ' << y << " | " << a << ' ' << b << '\n';

        if (x != -1 && a != -1 && x == a) mxs = max(mxs, x);
        if (x != -1 && b != -1 && x == b) mxs = max(mxs, x);

        if (y != -1 && a != -1 && y == a) mxs = max(mxs, y);
        if (y != -1 && b != -1 && y == b) mxs = max(mxs, y);

        if (x != -1 && a != -1 && abs(x - a) != 1) mxs = max(mxs, min(x, a));
        if (x != -1 && b != -1 && abs(x - b) != 1) mxs = max(mxs, min(x, b));
        
        if (y != -1 && a != -1 && abs(y - a) != 1) mxs = max(mxs, min(y, a));
        if (y != -1 && b != -1 && abs(y - b) != 1) mxs = max(mxs, min(y, b));

        if (x != -1 && y != -1) mxs = max(mxs, min(x, y));
        if (a != -1 && b != -1) mxs = max(mxs, min(a, b));

        ++mxs;

        mx = max(mx, mxs);
    }

    cout << mx << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
