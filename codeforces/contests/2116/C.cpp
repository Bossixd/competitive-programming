#include <iostream>
#include <numeric>

using namespace std;

void run() {
    int n;
    cin >> n;

    int nums[n];

    for (int i = 0; i < n; ++i) cin >> nums[i];

    int _gcd = nums[0];
    int _mn = nums[0];
    for (int i = 1; i < n; ++i) {
        _gcd = gcd(nums[i], _gcd);
        _mn = min(_mn, nums[i]);
    }

    int tries = 0;

    if (_gcd == _mn) {
        for (int i = 0; i < n; ++i)
            if (nums[i] != _gcd)
                tries++;
        cout << tries << '\n';
        return;
    }

    tries++;

    int dp[5001];
    int mx = 0;
    
    for (int i = 0; i < 5001; ++i) dp[i] = 0;

    for (int i = 0; i < n; ++i) {
        mx = max(mx, nums[i]);
        dp[nums[i]] = 1;
    }

    for (int i = mx; i >= 0; --i) {
        if (dp[i] == 0) continue;
        for (int j = 0; j < n; ++j) {
            int g = gcd(i, nums[j]);
            if (dp[g] == 0) dp[g] = dp[i] + 1;
            else dp[g] = min(dp[g], dp[i] + 1);
        }
    }

    for (int i = 0; i < n; ++i)
        if (nums[i] != _gcd)
            dp[_gcd]++;

    cout << dp[_gcd] - 2 << '\n';
}

int main() {
    int N;
    cin >> N;
    while (N--)
        run();
}

/*

If there is a 1, the number of steps is number of numbers not equal to 1

*/