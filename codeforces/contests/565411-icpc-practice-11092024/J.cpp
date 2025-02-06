#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[2][n];
    int cur = 0, last;
    int mx = 0;
    int start, end;
    for (int i = 0; i < n; ++i) {
        cin >> dp[cur][i];
        if (dp[cur][i] > mx) {
            start = i; end = i;
            mx = dp[cur][i];
        }
    }

    for (int l = 2; l <= n; ++l) {
        last = cur;
        if (cur == 0) cur = 1;
        else cur = 0;

        for (int i = 0; i < n - l + 1; ++i) {
            dp[cur][i] = min(dp[last][i], dp[last][i + 1]);
            if (l * dp[cur][i] > mx) {
                start = i; end = i + l;
                mx = l * dp[cur][i];
            }
        }
    }
    cout << start + 1 << ' ' << end << ' ' << mx << '\n';
}