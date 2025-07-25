#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int dp[2][5002];

    int v[n];
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vector<vector<pair<int, int>>> vp, vn;
    unordered_map<int, int> mp;

    for (int i = 0; i <= n; ++i) {
        if (i == n || v[i] == 0) {
            if (mp.size() == 0) continue;

            vector<pair<int, int>> vvp, vvn;
            for (auto &[k, c] : mp) {
                if (k > 0)
                    vvp.push_back(make_pair(k, c));
                else
                    vvn.push_back(make_pair(-k, c));
            }

            sort(vvp.begin(), vvp.end());
            sort(vvn.begin(), vvn.end());

            vp.push_back(vvp);
            vn.push_back(vvn);
            mp.clear();
        } else mp[v[i]]++;
    }

    int cnt = 0, idx = 0, mx = 0;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            ++cnt;
            dp[cnt % 2][0] = dp[(cnt - 1) % 2][0];
            dp[cnt % 2][cnt] = dp[(cnt - 1) % 2][cnt - 1];
            for (int j = 1; j < cnt; ++j)
                dp[cnt % 2][cnt - j] = max(dp[(cnt - 1) % 2][cnt - j - 1], dp[(cnt - 1) % 2][cnt - j]);
        } else {
            int idxx = 0, cntt = 0;
            for (int j = 0; j <= cnt; ++j) {
                if (idxx != vp[idx].size() && j >= vp[idx][idxx].first) cntt += vp[idx][idxx++].second;
                dp[cnt % 2][cnt - j] += cntt;
            }
            
            idxx = 0;
            cntt = 0;
            for (int j = 0; j <= cnt; ++j) {
                if (idxx != vn[idx].size() && j >= vn[idx][idxx].first) cntt += vn[idx][idxx++].second;
                dp[cnt % 2][j] += cntt;
                mx = max(mx, dp[cnt % 2][j]);
            }
            while (i != n && v[i] != 0) ++i;
            --i;

            ++idx;
        }
    }
    cout << mx << '\n';
}