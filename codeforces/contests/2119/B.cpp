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
    int n, px, py, qx, qy;
    cin >> n >> px >> py >> qx >> qy;

    qx -= px;
    qy -= py;

    double d = sqrt(qx * qx + qy * qy);

    vector<int> as(n);
    for (int i = 0; i < n; ++i) cin >> as[i];

    sort(as.begin(), as.end());

    if (n == 1) {
        if (d == as[0] || d == -as[0]) cout << "Yes\n";
        else cout << "No\n";
        return;
    }

    vector<pair<int, int>> v;
    vector<pair<int, int>> q;
    
    if (as[1] >= as[0]) {
        v.push_back(mp(- as[0] - as[1], + as[0] - as[1]));
        v.push_back(mp(- as[0] + as[1], + as[0] + as[1]));
    } else {
        v.push_back(mp(- as[0] - as[1], - as[0] + as[1]));
        v.push_back(mp(+ as[0] - as[1], + as[0] + as[1]));
    }

    for (int i = 2; i < n; ++i) {
        for (auto &[s, e] : v) {
            q.push_back(mp(s - as[i], e - as[i]));
            q.push_back(mp(s + as[i], e + as[i]));
        }
        
        sort(q.begin(), q.end(), [](const pair<int, int>& o1, const pair<int, int>& o2) {
            return o1.second < o2.second;
        });
        sort(q.begin(), q.end());

        v.clear();

        int cs = q[0].first, ce = q[0].second;

        for (int i = 1; i < q.size(); ++i) {
            if (q[i].first <= ce) ce = max(ce, q[i].second);
            else {
                v.push_back(mp(cs, ce));
                cs = q[i].first;
                ce = q[i].second;
            }
        }
        v.push_back(mp(cs, ce));

        q.clear();
    }
    
    // cout << '\n';
    // for (auto &[s, e] : v) {
    //     cout << s << ' ' << e << '\n';
    // }
    

    for (auto &[s, e] : v) {
        if (d >= s && d <= e) {
            cout << "Yes\n";
            return;
        }
    }
    
    cout << "No\n";
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
