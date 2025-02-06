#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void test_case() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<pair<int, int> > v(n + m);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    for (int i = n; i < n + m; ++i) {
        cin >> v[i].first >> v[i].second;
        v[i].second *= -1;
    }

    sort(v.begin(), v.end());
    priority_queue<int> pq;
    int k = 1;
    int cnt = 0;

    for (auto i : v) {
        // cout << i.first << ' ' << i.second << '\n';
        if (i.second < 0) {
            pq.push(-i.second);
        } else {
            // cout << i.second - i.first + 1 << '\n';
            while (k <= i.second - i.first + 1) {
                if (pq.empty()) {
                    cout << "-1\n";
                    return;
                }
                k += pq.top();
                // cout << "Add " << pq.top() << ' ' << k << '\n';
                pq.pop();
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--)
        test_case();
}