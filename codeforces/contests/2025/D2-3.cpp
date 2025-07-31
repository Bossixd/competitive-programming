#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct DifferenceArray {
    vector<int> v;
    DifferenceArray(int n): v(n, 0) {};

    void add(int l, int r, int val) {
        if (r < l) return;
        v[l] += val;
        v[r + 1] -= val;
    }

    void push(vector<int>& vec) {
        int n = v.size();
        int m = vec.size();
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            sm += v[i];
            v[i] = 0;
            if (i < m)
                vec[i] += sm;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(2, vector<int>(5005));

    int v[2000005];
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    DifferenceArray da(m + 5);

    int cnt = 0;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            da.push(dp[cnt % 2]);

            ++cnt;

            dp[cnt % 2][0] = dp[(cnt - 1) % 2][0];
            dp[cnt % 2][cnt] = dp[(cnt - 1) % 2][cnt - 1];
            for (int j = 1; j < cnt; ++j)
                dp[cnt % 2][cnt - j] = max(dp[(cnt - 1) % 2][cnt - j - 1], dp[(cnt - 1) % 2][cnt - j]);

        } else {
            if (v[i] > 0)
                da.add(0, cnt - v[i], 1);
            else
                da.add(-v[i], m, 1);
        }
    }

    da.push(dp[cnt % 2]);

    cout << *max_element(dp[cnt%2].begin(), dp[cnt%2].end()) << '\n';
}