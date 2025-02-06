#include <iostream>
#include <vector>
using namespace std;

int w;
int N;
int dp[2000][2000];

int test(int i, int Q, int *nums) {
    if (dp[i][Q] != -1) return dp[i][Q];

    if (i == N - 1) {
        if (Q >= 1) return 0;
        else return 1;
    }
    if (Q == 0)
        return N - i - 1;

    int x = i + 1;
    while (x < N && nums[x] - nums[i] <= nums[i] + w - 1) x++;
    x--;

    int y = i + 1;
    while (y < N && nums[y] - nums[i] <= nums[i] + w * 2 - 1) y++;
    y--;

    dp[i][Q] = min((x == i) ? test(x + 1, Q, nums) + 1 : test(x, Q, nums) + 1, test(y, Q - 1, nums));
    return dp[i][Q];
}

int main() {
    int P, Q;
    cin >> N >> P >> Q;

    if (P + Q >= N) {
        cout << 1 << '\n';
        return 0;
    }
    
    int nums[N];
    for (int n = 0; n < N; ++n) cin >> nums[n];

    int l = 0, h = nums[N - 1];
    while (l < h) {
        w = l + (h - l) / 2;
        for (int i = 0; i < 2000; ++i)
            for (int j = 0; j < 2000; ++j)
                dp[i][j] = -1;
        if (test(0, Q, nums) <= P)
            h = w - 1;
        else
            l = w + 1;
    }
    cout << l << '\n';
}