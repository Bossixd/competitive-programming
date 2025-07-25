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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> v[i][j];

    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    });
    sort(v.begin(), v.end());

    // for (auto i : v)
    //     cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    // cout << '\n';

    priority_queue<int> pq;
    pq.push(k);

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (pq.empty()) break;
        if (pq.top() >= v[i][0]) {
            if (pq.top() <= v[i][1])
                pq.push(v[i][2]);
        } else {
            mx = max(mx, pq.top());
            pq.pop();
            --i;
        }
    }

    while (!pq.empty()) {
        mx = max(mx, pq.top());
        pq.pop();
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
